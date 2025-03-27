#include<bits/stdc++.h>
#define int long long
using namespace std;
 
signed main(){
    int n, m, mod = 1e9 + 7;
    cin >> n >> m;
    vector<int> a(n);
    for(int &e: a)
        cin >> e;
    vector<int> b(n);
    for(int &e: b)
        cin >> e;
    vector<int> dp(m + 1, 0);
    for(int i = 0; i < n; ++i)
        for(int j = m; j >= a[i]; --j)
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
    cout << *max_element(dp.begin(), dp.end()) << '\n';
}