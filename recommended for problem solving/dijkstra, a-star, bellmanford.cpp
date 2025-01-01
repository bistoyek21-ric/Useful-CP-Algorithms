#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, inf = (1LL << 60);

int n, m, k;

vector<vector<int>> g[maxn], edge;

int dist[maxn], par[maxn];

//#define MULTI_TEST
#define IOS

void preprocess(){
	return;
}

void bellmanford(int source){
    for(int i = 0; i < n; ++i)
        for(auto e: edge){
            int u = e[0], v = e[1], w = e[2];
            if(dist[u] + w < dist[v])
                dist[v] = dist[u] + w, par[v] = u;
        }
    return;
}

void dijkstra(int source){
    set<vector<int>> cand;
    cand.insert({0LL, source});
    while(cand.size()){
        vector<int> best = (*cand.begin());
        cand.erase(best);
        int w = best[0], u = best[1];
        for(auto v: g[u])
            if(v[1] + w < dist[v[0]]){
                cand.erase({dist[v[0]], v[0]});
                dist[v[0]] = v[1] + w;
                cand.insert({dist[v[0]], v[0]});
                par[v[0]] = u;
            }
    }
    return;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
        edge.pb({u, v, w});
    }
    int vert[2];
    cin >> vert[0] >> ver[1];
    --vert[0], --vert[1];
    for(int i = 0; i < n; ++i)
        dist[i] = par[i] = inf;
    dist[vert[0]] = 0;
    par[vert[0]] = vert[0];
    dijkstra(vert[0]);
    if(dist[vert[1]] == inf)
        cout << -1 << '\n';
    else{
        vector<int> ans;
        int u = vert[1];
        while(true){
            ans.pb(u + 1);
            if(u == vert[0])
                break;
            else
                u = par[u];
        }
        reverse(ans.begin(), ans.end());
        cout << dist[vert[1]] << '\n';
        for(int e: ans)
            cout << e << " ";
        cout << '\n';
    }
}

void ready(){
    return;
}

signed main(){
    #ifdef IOS
    ios::sync_with_stdio(0), cin.tie(0);
    #endif // IOS
    int t = 1;
    #ifdef MULTI_TEST
	cin >> t;
	#endif // MULTI_TEST
	preprocess();
    while(t--){
        test_case();
        if(t)
            ready();
    }
    return 0;
}
