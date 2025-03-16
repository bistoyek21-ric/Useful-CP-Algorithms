#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 205, maxm = 1e3 + 5;

int n, m, k, a[maxn], dp[maxn][maxn], inf = (1LL << 60);

void preprocess(){

	return;
}

void give_input(){
    cin >> n;
    for(int i = 0; i <= n; ++i)
        cin >> a[i];
    cout << dp[0][n] << '\n';
    return;
}

void process(){
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j + i <= n; ++j){
            if(i == 1)
                dp[j][i + j] = 0;
            else{
                dp[j][i + j] = inf;
                for(int k = j + 1; k < j + i; ++k)
                    dp[j][i + j] = min(dp[j][k] + dp[k][j + i] + a[j] * a[k] * a[j + i], dp[j][j + i]);
            }
        }
    }
    return;
}

void get_output(){
    cout << dp[0][n] << '\n';
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
