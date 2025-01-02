#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5;

int n, m, k, a[maxn], dp[maxn], dp1[maxn];
int ans;
vector<int> g[maxn];

void preprocess(){

	return;
}


void dfs(int u, int prev){
    for(int v: g[u])
        if(prev != v)
            dfs(v, u);
    for(int v: g[u]){
        if(prev == v)
            continue;
        int num = dp[u];
        if(dp[u] <= num + dp[v] - 2 * k)
            dp[u] = num + dp[v] - 2 * k;
        if(dp[u] <= num + dp1[v])
            dp[u] = num + dp1[v];
        dp1[u] += max(dp[v], dp1[v]);
    }
    ans = max(ans, dp[u]);
    ans = max(ans, dp1[u]);
    return;
}

void give_input(){
    cin >> n >> k;
    m = n - 1;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        dp[i] = a[i];
        dp1[i] = 0;
        g[i].clear();
    }
    while(m--){
        int u, v, w;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    dfs(0, -1);
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
	cin >> t;
	preprocess();
    while(t--){
        give_input();
        process();
        get_output();
    }
    return 0;
}
