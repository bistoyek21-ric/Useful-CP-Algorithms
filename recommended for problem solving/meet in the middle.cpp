#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;
 
int constexpr maxn = 2e5 + 5, inf = (1LL << 60);
 
int n, m, k;
 
void preprocess(){
	return;
}
 
void test_case(){
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> sum[2];
    int sz[2] = {n / 2, (n + 1) / 2};
    for(int k = 0; k < 2; ++k)
        for(int i = 0; i < (1 << sz[k]); ++i){
            int num = 0;
            for(int j = 0; j < sz[k]; ++j)
                if((i >> j) & 1)
                    num += a[j + (n / 2) * k];
            sum[k].pb(num);
        }
    sort(sum[0].begin(), sum[0].end());
    int ans = 0;
    for(int e: sum[1])
        ans += upper_bound(sum[0].begin(), sum[0].end(), m - e) - lower_bound(sum[0].begin(), sum[0].end(), m - e);
    cout << ans << '\n';
	return;
}
 
void ready(){
    return;
}
 
signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	preprocess();
    while(t--){
        test_case();
        if(t)
            ready();
    }
    return 0;
}
