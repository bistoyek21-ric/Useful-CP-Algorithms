#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5;

vector<vector<int>> g[maxn];
vector<int> euler_tour;
bool mark[maxn];
int n, m;

void dfs(int u){
    for(auto v: g[u])
        if(!mark[v[1]]){
            mark[v[1]] = true;
            euler_tour.pb(v[1]);
            dfs(v[0]);
        }
    return;
}

bool is_eulerian(){
    int odd_count = 0;
    for(int i = 0; i < n; ++i)
        if(g[i].size() % 2){
            ++odd_count;
            if(odd_count == 3)
                return false;
        }
    return (odd_count == 0 || odd_count == 2);
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    if(!is_eulerian()){
        cout << "Graph is not Eulerian" << '\n';
        return;
    }
    int start_node = 0;
    for(int i = 0; i < n; ++i)
        if(g[i].size() % 2){
            start_node = i;
            break;
        }
    if(g[start_node].size() % 2)
        cout << "Graph is semi Eulerian" << '\n';
    dfs(start_node);
    for(int e: euler_tour)
        cout << e + 1 << " ";
    cout << '\n';
    return;
}

void preprocess(){
    return;
}

void ready(){
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    preprocess();
    while(t--){
        test_case();
        if(t)
            ready();
    }
    return 0;
}
