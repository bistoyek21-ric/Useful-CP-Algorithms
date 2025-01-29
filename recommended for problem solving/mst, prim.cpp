#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 9, maxm = 109;

int n, m;

bool mark[maxn];

vector<vector<int>> g[maxn], g1[maxn];

void preprocess(){

	return;
}

int prim(int source){
    set<vector<int>> candidates;
    mark[source] = true;
    int total = 0;
    for(auto v: g[source])
        candidates.insert({v[1], source, v[0]});
    while(!candidates.empty()){
        auto candid = *candidates.begin();
        candidates.erase(candid);
        if(mark[candid[2]])
            continue;
        g1[candid[1]].pb({candid[2], candid[0]});
        g1[candid[2]].pb({candid[1], candid[0]});
        mark[candid[2]] = true;
        total += candid[0];
        for(auto v: g[candid[2]])
            if(!mark[v[0]])
                candidates.insert({v[1], candid[2], v[0]});
    }
    return total;
}

void give_input(){
    cin >> n >> m;
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        if(!mark[i])
            ans += prim(i);
    cout << ans << '\n';
    return;
}

void process(){

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
    while(t--){
        give_input();
        process();
        get_output();
    }
    return 0;
}
