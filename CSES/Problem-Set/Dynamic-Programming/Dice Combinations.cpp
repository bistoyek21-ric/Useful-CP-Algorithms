#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e6 + 6;

int n, m, dp[maxn], mod = 1e9 + 7;

void preprocess(){

	return;
}

void give_input(){
    cin >> n;
    return;
}

void process(){
    dp[0] = 1;
    for(int i = 1; i <= n; ++i)
        for(int j = max(0LL, i - 6); j < i; ++j)
            dp[i] += dp[j], dp[i] %= mod;
    return;
}

void get_output(){
    cout << dp[n] << '\n';
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