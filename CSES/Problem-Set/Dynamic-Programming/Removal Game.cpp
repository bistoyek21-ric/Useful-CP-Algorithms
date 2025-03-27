#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 5002;

int n, a[maxn], dp[maxn][maxn][2];

signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 0; i + j <= n; ++j){
            if(i == 1)
                dp[j][j + 1][0] = a[j], dp[j][j + 1][1] = 0;
            else{
                if(a[i + j - 1] + dp[j][i + j - 1][1] < a[j] + dp[j + 1][i + j][1]){
                    dp[j][i + j][0] = a[j] + dp[j + 1][i + j][1];
                    dp[j][i + j][1] = dp[j + 1][i + j][0];
                }
                else{
                    dp[j][i + j][0] = a[i + j - 1] + dp[j][i + j - 1][1];
                    dp[j][i + j][1] = dp[j][i + j - 1][0];
                }
            }
        }
    }
    cout << dp[0][n][0] << '\n';
}