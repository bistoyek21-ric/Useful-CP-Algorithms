#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int n, m, mod = 1e9 + 7;
    cin >> n;
    vector<string> a(n);
    for(string &e: a)
        cin >> e;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = (a[0][0] == '.' ? 1 : 0);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            if(a[i][j] == '.'){
                if(i + 1 < n)
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % mod;
                if(j + 1 < n)
                    dp[i][j + 1] = (dp[i][j + 1] + dp[i][j]) % mod;
            }
    if(a[n - 1][n - 1] != '.')
        dp[n - 1][n - 1] = 0;
    cout << dp[n - 1][n - 1] << '\n';
}