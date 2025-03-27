#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
    vector<int> dp(m + 1, 0);
    dp[0] = 1;
    vector<int> a(n);
    for(auto &e: a)
        cin >> e;
    for(int j = 0; j <= m; ++j)
        for(int i = 0; i < n; ++i)
            if(0 <= j - a[i])
                dp[j] = (dp[j] + dp[j - a[i]]) % mod;
    cout << dp[m] << '\n';
}