#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, inf = (1LL << 60);

int n, m, k, mod = 998244353;

vector<int> g[maxn];

int lvl[maxn], par[maxn];

//#define MULTI_TEST
#define IOS

void preprocess(){
	return;
}

void bfs(vector<int> sources){
    queue<int> bfsq;
    for(int v: sources){
        lvl[v] = 0;
        par[v] = v;
        bfsq.push(v);
    }
    while(!bfsq.empty()){
        int u = bfsq.front();
        bfsq.pop();
        for(int v: g[u])
            if(lvl[v] == inf){
                lvl[v] = lvl[u] + 1;
                bfsq.push(v);
                par[v] = u;
            }
    }
    return;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        lvl[i] = par[i] = inf;
    int vert[2];
    cin >> vert[0] >> vert[1];
    --vert[0], --vert[1];
    while(m--){
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs({vert[0]});
    if(lvl[vert[1]] == inf){
        cout << -1 << '\n';
    }
    else{
        cout << lvl[vert[1]] << '\n';
        int u = vert[1];
        vector<int> ans;
        while(true){
            ans.pb(u + 1);
            if(u == vert[0])
                break;
            else
                u = par[u];
        }
        reverse(ans.begin(), ans.end());
        for(int e: ans)
            cout << e << " ";
        cout << '\n';
    }
	return;
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
