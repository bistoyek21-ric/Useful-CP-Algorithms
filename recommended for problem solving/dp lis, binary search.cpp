#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, inf = (1LL << 60), mod = 998244353;

int n, m, k, a[maxn], dp[maxn], par[maxn];

void preprocess(){

	return;
}

void give_input(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> lis;
    for(int i = 0; i < n; ++i){
        int pos = lower_bound(lis.begin(), lis.end(), vector<int>{a[i], inf}) - lis.begin();
        dp[i] = pos + 1;
        if(pos)
            par[i] = (pos ? lis[pos - 1][1] : i);
        if(pos < lis.size())
            lis[pos] = {a[i], i};
        else
            lis.pb({a[i], i});
    }
    vector<int> ans;
    int ind_max = 0;
    for(int i = 1; i < n; ++i)
        if(dp[ind_max] < dp[i])
            ind_max = i;
    cout << dp[ind_max] << '\n';
    while(true){
        ans.pb(ind_max);
        if(par[ind_max] == ind_max)
            break;
        ind_max = par[ind_max];
    }
    reverse(ans.begin(), ans.end());
    for(int e: ans)
        cout << a[e] << " ";
    cout << '\n';
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
