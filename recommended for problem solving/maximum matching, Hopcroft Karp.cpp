#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 1005, inf = (1LL << 60);

vector<int> g[maxn];

int n, m, dist[maxn], matchU[maxn], matchV[maxn];

bool bfs(){
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(!matchU[i]){
            dist[i] = 0;
            q.push(i);
        }
        else
            dist[i] = inf;
    }
    dist[0] = inf;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u] < dist[0])
            for(int v: g[u])
                if(dist[matchV[v]] == inf){
                    dist[matchV[v]] = dist[u] + 1;
                    q.push(matchV[v]);
                }
    }
    return dist[0] != inf;
}

bool dfs(int u){
    if(u){
        for(int v: g[u]){
            if(dist[matchV[v]] == dist[u] + 1){
                if(dfs(matchV[v])){
                    matchV[v] = u;
                    matchU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = inf;
        return false;
    }
    return true;
}

int hopcroft_karp(){
    int matching = 0;
    while(bfs())
        for(int i = 1; i <= n; ++i)
            if(!matchU[i] && dfs(i))
                ++matching;
    return matching;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int max_matching = hopcroft_karp();
    cout << "Maximum Matching: " << max_matching << '\n';
    cout << "Edges in the Matching:\n";
    for(int i = 1; i <= n; ++i)
        if(matchU[i])
            cout << i << " - " << matchU[i] << '\n';
    return;
}

void preprocess(){
    return;
}

void ready(){
    for(int i = 0; i <= n; ++i){
        matchU[i] = matchV[i] = 0;
        g[i].clear();
    }
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
