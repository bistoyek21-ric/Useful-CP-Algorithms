#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 4e5 + 5, inf = (1LL << 60);

int n, m, k = 0;

vector<vector<int>> edge;
vector<vector<int>> g[maxn], g_c[maxn];
bool is_cut_edge[maxn], mark[maxn];
int h[maxn], col[maxn], X2col[maxn], cherry[maxn], cld[maxn];
vector<int> X2comp, comp, X2root;

void preprocess(){
	return;
}

int dfs(int u, int h_cnt, int color, int ind = -1){
    col[u] = color;
    h[u] = h_cnt;
    ++comp[color];
    int mn = h[u];
    for(const auto &v: g[u]){
        if(col[v[0]] == -1){
            is_cut_edge[v[1]] = true;
            int res = dfs(v[0], h_cnt + 1, color, v[1]);
            if(res <= h[u])
                is_cut_edge[v[1]] = false;
            mn = min(mn, res);
        }
        else if(ind != v[1])
            mn = min(mn, h[v[0]]);
    }
    return mn;
}

void dfs1(int u, int color){
    X2col[u] = color;
    ++X2comp[color];
    for(const auto &v: g[u]){
        if(is_cut_edge[v[1]])
            continue;
        if(X2col[v[0]] == -1)
            dfs1(v[0], color);
    }
    return;
}

void dfs2(int u, int prv = -1){
    mark[u] = true;
    cld[u] = X2comp[u];
    int sum2 = 0, sum = 0;
    for(const auto &v: g_c[u])
        if(v[0] != prv){
            dfs2(v[0], u);
            cld[u] += cld[v[0]];
            sum += cld[v[0]];
            sum2 += cld[v[0]] * cld[v[0]];
        }
    if(prv != -1){
        int other_cld = comp[col[X2root[u]]] - cld[u];
        sum += other_cld;
        sum2 += other_cld * other_cld;
    }
    cherry[u] = X2comp[u] * ((sum * sum) - sum2) / 2;
    return;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        edge.pb({u, v});
        g[u].pb({v, i});
        g[v].pb({u, i});
    }
    for(int i = 0; i < n; ++i)
        X2col[i] = col[i] = -1;
    int cnt = 0;
    for(int i = 0; i < n; ++i)
        if(col[i] == -1){
            comp.pb(0);
            dfs(i, 0, cnt);
            ++cnt;
        }
    cnt = 0;
    for(int i = 0; i < n; ++i)
        if(X2col[i] == -1){
            X2comp.pb(0);
            X2root.pb(i);
            dfs1(i, cnt);
            ++cnt;
        }
    for(int i = 0; i < m; ++i)
        if(is_cut_edge[i]){
            int u, v;
            u = X2col[edge[i][0]];
            v = X2col[edge[i][1]];
            g_c[u].pb({v, i});
            g_c[v].pb({u, i});
        }
    int ans = 0;
    for(int i = 0; i < X2comp.size(); ++i){
        ans += X2comp[i] * (X2comp[i] - 1) * (X2comp[i] - 2);
        ans += X2comp[i] * (X2comp[i] - 1) * (comp[col[X2root[i]]] - X2comp[i]) * 2;
    }
    for(int i = 0; i < X2comp.size(); ++i)
        if(!mark[i])
            dfs2(i);
    for(int i = 0; i < X2comp.size(); ++i)
        ans += cherry[i] * 2;
    cout << ans << '\n';
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
