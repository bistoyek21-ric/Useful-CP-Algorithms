#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 100'005;

int n, a[maxn];

bool dp[maxn];

signed main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    dp[0] = true;
    for(int i = 0; i < n; ++i)
        for(int j = maxn - 1; j >= a[i]; --j)
            dp[j] |= dp[j - a[i]];
    vector<int> ans;
    for(int i = 1; i < maxn; ++i)
        if(dp[i])    
            ans.push_back(i);
    cout << ans.size() << '\n';
    for(auto e: ans)
        cout << e << " ";
    cout << '\n';
}