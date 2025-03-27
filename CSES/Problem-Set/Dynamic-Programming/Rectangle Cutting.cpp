#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 512;

bool mark[maxn][maxn];
int dp[maxn][maxn];

int solve(int n, int m){
    if(n < m)
        swap(n, m);
    if(mark[n][m])
        return dp[n][m];
    mark[n][m] = true;
    if(!(n * m) || n == m){
        dp[n][m] = 0;
        return dp[n][m];
    }
    dp[n][m] = n * m;
    for(int i = 1; i <= n - i; ++i)
        dp[n][m] = min(dp[n][m], solve(i, m) + solve(n - i, m) + 1);
    for(int i = 1; i <= m - i; ++i)
        dp[n][m] = min(dp[n][m], solve(n, i) + solve(n, m - i) + 1);
    return dp[n][m]; 
}

signed main(){
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << '\n';
}