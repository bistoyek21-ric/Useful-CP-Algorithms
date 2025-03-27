#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int constexpr maxn = 1'009, maxm = 10;

int dp[maxn][1 << maxm];

signed main(){
    int n, m, mod = 1e9 + 7;
    cin >> m >> n;
    dp[0][0] = 1;
    for(int i = 0; i < n; ++i){
        for(int j = !i; j < (m << 1); ++j){
            if(!j)
                dp[i][j] = dp[i - 1][(m << 1) - 1];
            else{

            }
        }
    }
    cout << dp[n][0] << '\n';
}