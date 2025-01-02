#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, maxlg = 20;

bool mark[maxn];

int timer, tin[maxn], tout[maxn], par[maxn][maxlg];

vector<int> g[maxn];

void ready(){
    for(int i = 0; i < n; ++i)
        g[i].clear();
    return;
}

void dfs(int u, int p){
    par[u][0] = p;
    for(int i = 1; i < maxlg; ++i)
        par[u][i] = par[par[u][i - 1]][i - 1];
    tin[u] = ++timer;
    mark[u] = true;
    for(int v: g[u])
        if(!mark[v])
            dfs(v, u);
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

void preprocess(){
	return;
}

void give_input(){
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
