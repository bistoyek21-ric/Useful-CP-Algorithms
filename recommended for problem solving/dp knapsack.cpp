#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, maxm = 1e3 + 5;

int n, m, k, a[maxn], dp[maxm][maxn], mod = 998244353;

void preprocess(){

	return;
}

void give_input(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < maxm; ++i){
        for(int j = 0; j < n; ++j){
            dp[i][j] = (j ? dp[i][j - 1] : 0);
            if(a[j] <= i)
                dp[i][j] += (j ? dp[i - a[j]][j - 1] : 0) + (int)(i == a[j]);
            dp[i][j] %= mod;
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i)
        ans = (ans + ((dp[m][i] * (n - i)) % mod)) % mod;
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
