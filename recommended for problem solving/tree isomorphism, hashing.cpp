#include<bits/stdc++.h>
#define int long long
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;

int constexpr maxn = 1000004, mod = 1000000021, bs = 2;

bool ans;

int n[2], h[2][maxn], sh[maxn], sc[maxn], cld[2][maxn], p4[maxn];

vector<int> g[2][maxn];

vector<pair<int, int>> ahs;

void preprocess(){
    p4[0] = 1;
    for(int i = 1; i < maxn; ++i)
        p4[i] = (p4[i - 1] * bs * bs) % mod;
    return;
}

void dfs(int u, int par, int i){
    cld[i][u] = 1;
    if(par != -1 && g[i][u].size() == 1){
        h[i][u] = 2;
        return;
    }
    h[i][u] = 1;
    for(int &v: g[i][u])
        if(v != par){
            dfs(v, u, i);
            cld[i][u] += cld[i][v];
        }
    ahs.clear();
    for(int &v: g[i][u])
        if(v != par)
            ahs.emplace_back(pair<int, int>{h[i][v], v});
    sort(ahs.begin(), ahs.end());
    for(auto &e: ahs){
        h[i][u] = (h[i][u] * p4[cld[i][e.second]]) % mod;
        h[i][u] = (h[i][u] + e.first) % mod;
    }
    h[i][u] = (h[i][u] * bs) % mod;
    return;
}

void dfs1(int u, int par){
    sh[u] = h[1][u];
    sc[u] = cld[1][u];
    if(~par){////////////////~par
        sh[par] = h[1][par];
        sc[par] = cld[1][par];
        cld[1][par] = n[1] - cld[1][u];
        cld[1][u] = n[1];
        ////-------------- update par -> child
        ahs.clear();
        for(int &v: g[1][par])
            if(v != u)
                ahs.emplace_back(pair<int, int>{h[1][v], v});
        h[1][par] = 1;
        if(g[1][par].size() == 1)
            h[1][par] *= bs;
        else{
            sort(ahs.begin(), ahs.end());
            for(auto &e: ahs){
                h[1][par] = (h[1][par] * p4[cld[1][e.second]]) % mod;
                h[1][par] = (h[1][par] + e.first) % mod;
            }
            h[1][par] = (h[1][par] * bs) % mod;
        }
        ////------------- update u -> root
        ahs.clear();
        for(int &v: g[1][u])
            ahs.emplace_back(pair<int, int>{h[1][v], v});
        h[1][u] = 1;
        sort(ahs.begin(), ahs.end());
        for(auto &e: ahs){
            h[1][u] = (h[1][u] * p4[cld[1][e.second]]) % mod;
            h[1][u] = (h[1][u] + e.first) % mod;
        }
        h[1][u] = (h[1][u] * bs) % mod;
        if(h[0][0] == h[1][u])
            ans = true;
    }////////////////// ~par end
    else{
        if(h[0][0] == h[1][u])
            ans = true;
    }
    for(int &v: g[1][u])
        if(v != par)
            dfs1(v, u);
    if(~par){
        h[1][par] = sh[par];
        cld[1][par] = sc[par];
    }
    h[1][u] = sh[u];
    cld[1][u] = sc[u];
    return;
}

void process(){
    ans = false;
    if(n[0] != n[1])
        return;
    if(n[0] == 1){
        ans = true;
        return;
    }
    dfs(0, -1, 0);
    dfs(0, -1, 1);
    dfs1(0, -1);
    return;
}

void get_input(){
    for(int k = 0; k < 2; ++k){
        cin >> n[k];
        for(int i = 0; i < n[k] - 1; ++i){
            int u, v;
            cin >> u >> v;
            g[k][--u].emplace_back(--v);
            g[k][v].emplace_back(u);
        }
    }
    return;
}

void give_output(){
    if(ans)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    for(int k = 0; k < 2; ++k)
        for(int i = 0; i < n[k]; ++i)
            g[k][i].clear();
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int tst = 1;
    //cin >> tst;
    preprocess();
    while(tst--){
        get_input();
        process();
        give_output();
    }
    return 0;
}
