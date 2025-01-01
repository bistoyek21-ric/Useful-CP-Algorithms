#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

//#define CLASSIC_DSU
#define MST

#define SIZE
#define FAST
//#define HIGHT

int constexpr maxn = 1e6 + 5, maxlg = 20, inf = (1LL << 60);

int n, m, k, q, rnk[maxn], pr[maxn];

int col[maxn];

int timer, tin[maxn], tout[maxn], par[maxn][maxlg], mn[maxn][maxlg];

vector<vector<int>> edge;

vector<pii> g[maxn];

void dfs(int u, int p, int w, int color){
    col[u] = color;
    par[u][0] = p;
    mn[u][0] = w;
    for(int i = 1; i < maxlg; ++i){
        par[u][i] = par[par[u][i - 1]][i - 1];
        mn[u][i] = min(mn[u][i - 1], mn[par[u][i - 1]][i - 1]);
    }
    tin[u] = ++timer;
    for(pii v: g[u])
        if(p != v.f0)
            dfs(v.f0, u, v.s0, color);
    tout[u] = ++timer;
    return;
}
//first is second's ancestor
bool ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if(ancestor(u, v))
        return u;
    if(ancestor(v, u))
        return v;
    for(int i = maxlg - 1; ~i; --i)
        if(!ancestor(par[u][i], v))
            u = par[u][i];
    return par[u][0];
}
//calculates the minimum weight in the path between a vertex u and vertex v
int find_mn(int u, int v){
    if(col[u] != col[v])
        return -inf;
    int ans = inf;
    int tmp_u = u, tmp_v = v;
    for(int i = maxlg - 1; ~i; --i){
        if(!ancestor(par[u][i], tmp_v)){
            ans = min(ans, mn[u][i]);
            u = par[u][i];
        }
        if(!ancestor(par[v][i], tmp_u)){
            ans = min(ans, mn[v][i]);
            v = par[v][i];
        }
    }
    if(!ancestor(u, tmp_v)){
        ans = min(ans, mn[u][0]);
        u = par[u][0];
    }
    if(!ancestor(v, tmp_u)){
        ans = min(ans, mn[v][0]);
        v = par[v][0];
    }
    return ans;
}

void ready(){
    for(int i = 0; i < n; ++i)
        pr[i] = i, rnk[i] = 1;
    return;
}

int get_pr(int u){
    #ifdef SIZE
    vector<int> v;
    while(u != pr[u])
        u = pr[u], v.pb(u);
    #elif HIGHT
    vector<int> v;
    while(u != pr[u])
        v.pb(u), u = pr[u];
    #endif // SIZE
    #ifdef FAST
    for(int e: v)
        pr[e] = u;
    #endif //FAST
    return u;
}

void unite(int u, int v){
    u = get_pr(u);
    v = get_pr(v);
    if(u == v)
        return;
    #ifdef SIZE
    if(rnk[u] < rnk[v])
        swap(u, v);
    rnk[u] += rnk[v];
    pr[v] = u;
    #elif HIGHT
    if(rnk[u] > rnk[v])
        swap(u, v);
    rnk[u] += (int)(rnk[v] == rnk[u]);
    pr[v] = u;
    #endif //SIZE
    return;
}

void preprocess(){
	return;
}

void give_input(){
	cin >> n;
	#ifdef MST
	cin >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        edge.pb({-w, u - 1, v - 1});
    }
    sort(edge.begin(), edge.end());
    for(int i = 0; i < m; ++i){
        int u, v;
        u = get_pr(edge[i][1]);
        v = get_pr(edge[i][2]);
        if(v != u){
            unite(u, v);
            g[edge[i][1]].pb(pii{edge[i][2], -edge[i][0]});
            g[edge[i][2]].pb(pii{edge[i][1], -edge[i][0]});
        }
    }
    int cnt = 1;
    for(int i = 0; i < n; ++i)
        if(!col[i])
            dfs(i, i, inf, cnt), ++cnt;
	#endif // MST
	return;
}

void process(){
    #ifdef CLASSIC_DSU
    cin >> q;
    for(int i = 0; i < q; ++i){
        string type;
        int u, v;
        cin >> type;
        if(type == "unite"){
            cin >> u >> v;
            unite(u - 1, v - 1);
        }
        if(type = "get_par"){
            cin >> u;
            cout << get_par(u - 1) << '\n';
        }
    }
    #endif //CLASSIC_DSU
    #ifdef MST
    cin >> q;
    for(int i = 0; i < q; ++i){
        int u, v, w, min_e;
        cin >> u >> v >> w;
        --u, --v;
        min_e = find_mn(u, v);
        /*
        cout << "______________\n";
        cout << "(u: " << u + 1 << ", v: " << v + 1 << ")\n";
        cout << "w: " << w << '\n';
        cout << "ans: " << min_e << '\n';
        */
        if(w <= min_e)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    #endif // MST
	return;
}

void get_output(){
	return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	preprocess();
	n = maxn;
	ready();
    while(t--){
        give_input();
        process();
        get_output();
        ready();
    }
    return 0;
}
