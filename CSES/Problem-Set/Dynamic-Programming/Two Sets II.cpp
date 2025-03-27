#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 200'005, mod = 1'000'000'007;

int n, a[maxn];

int dp[maxn];

signed main(){
    int n;
    cin >> n;
    if(n * (n + 1) % 4 != 0){
        cout << 0 << '\n';
        return 0;
    }
    int m = n * (n + 1) / 4;
    --n;
    for(int i = 0; i < n; ++i)
        a[i] = i + 1;
    dp[0] = 1;
    for(int i = 0; i < n; ++i)
        for(int j = maxn - 1; j >= a[i]; --j)
            dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    cout << dp[m] << '\n';
}