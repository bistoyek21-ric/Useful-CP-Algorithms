#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 1'000'009, mod = 1'000'000'007;
int dp[maxn][8];

signed main(){
    dp[1][1] = dp[1][2] = 1;
    vector<int> adj[8];
    adj[0] = {0, 1, 3};
    adj[1] = {0, 1, 3};
    adj[2] = {0, 1, 3};
    adj[3] = {2, 4, 5, 6, 7};
    adj[4] = {2, 4, 5, 6, 7};
    adj[5] = {2, 4, 5, 6, 7};
    adj[6] = {2, 4, 5, 6, 7};
    adj[7] = {2, 4, 5, 6, 7};
    for(int i = 2; i < maxn; ++i)
        for(int j = 0; j < 8; ++j)
            for(int e: adj[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][e]) % mod;
    int t;
    cin >> t;
    while(t--){
        int num;
        cin >> num;
        ++num;
        cout << (dp[num][1] + dp[num][3]) % mod << '\n';
    }
    return 0;
}