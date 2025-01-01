#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

const int N = 1e5 + 5;
vector<int> g[N * 2][2], topol;
int n, m, cnt, col[N * 2];
bool mark[N * 2];

void ready(){
    for(int i = 0; i < 2 * n; ++i){
        g[i][0].clear(), g[i][1].clear();
        mark[i] = col[i] = 0;
    }
    topol.clear();
    return;
}

int get_index(int u){
	return 0 < u ? (u - 1) * 2: ~u * 2 + 1;
}

void add_edge(int u, int v){
	g[u][0].pb(v);
	g[v][1].pb(u);
	return;
}

void add_clause(int u, int v){
	add_edge(u ^ 1, v);
	add_edge(v ^ 1, u);
	return;
}

void dfs(int u){
	mark[u] = true;
	for(int v: g[u][0])
		if(!mark[v])
			dfs(v);
	topol.pb(u);
	return;
}

void dfs1(int u){
	col[u] = cnt;
	mark[u] = true;
	for(int v: g[u][1])
		if(!mark[v])
			dfs1(v);
    return;
}

void give_input(){
	cin >> m >> n;
	ready(n);
	while(m--){
		int u, v;
		char c, c1;
		cin >> c >> u >> c1 >> v;
		if(c == '-')
            u *= -1;
        if(c1 == '-')
            v *= -1;
		u = get_index(u);
		v = get_index(v);
		add_clause(u, v);
	}
	return;
}

void process(){
	for(int i = 0; i < n * 2; ++i)
		if(!mark[i])
			dfs(i);
	reverse(topol.begin(), topol.end());
	for(int i = 0; i < n * 2; ++i)
        mark[i] = 0;
    cnt = 1;
	for(int u: topol)
		if(!mark[u]){
			dfs1(u);
			++cnt;
		}
    return;
}

void get_output(){
	for(int i = 0; i < n; ++i)
		if(col[i * 2] == col[i * 2 + 1]){
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
	cout << "YES" << '\n';
	for(int i = 0; i < n; ++i)
		if(col[i * 2 + 1] < col[i * 2])
            cout << '+';
        else
            cout << '-';
    cout << '\n';
    return;
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	while(t--){
        give_input();
        process();
        get_output();
	}
	return 0;
}
