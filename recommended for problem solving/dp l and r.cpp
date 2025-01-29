#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 109, maxm = 109;

int n, m, dp[maxn][maxn][maxm], divi[maxm][maxm], mod = 998244353;

void preprocess(){

	return;
}

void give_input(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
        int num;
        cin >> num;
        num %= m, num = (num + m) % m;
        dp[i][i + 1][num] = 1;
    }
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < m; ++j)
            divi[(i * j) % m][i] = j;
    for(int j = 2; j < n + 1; ++j)
        for(int i = 0; i < n; ++i){
            if(n < i + j)
                continue;
            int k = i + j;
            for(int i1 = i + 1; i1 < k; ++i1)
                for(int j1 = 0; j1 < m; ++j1){
                    dp[i][k][0] = (dp[i][k][0] + dp[i][i1][0]) % mod;
                    dp[i][k][0] = (dp[i][k][0] + dp[i1][k][j1]) % mod;
                    for(int j2 = 0; j2 < m; ++j2){
                        int num = (j1 - j2 + m) % m;
                        dp[i][k][j1] = (dp[i][k][j1] + dp[i][i1][j2]) % mod;
                        dp[i][k][j1] = (dp[i][k][j1] + dp[i1][k][num]) % mod;
                        if(j2){
                            dp[i][k][j1] = (dp[i][k][j1] + dp[i][i1][j2]) % mod;
                            dp[i][k][j1] = (dp[i][k][j1] + dp[i1][k][divi[j1][j2]]) % mod;
                        }
                    }
                }
        }
    int q;
    cin >> q;
    while(q--){
        int l, r, num;
        cin >> l >> r >> num;
        num %= m, num = (num + m) % m;
        cout << dp[l - 1][r][num] << '\n';
    }
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
