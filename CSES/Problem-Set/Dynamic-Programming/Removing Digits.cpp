#include<bits/stdc++.h>
using namespace std;

set<int> options(int n){
    set<int> res;
    while(n){
        res.insert(n % 10);
        n /= 10;
    }
    return res;
}

int main(){
    int n, m, mod = 1e9 + 7;
    cin >> m;
    vector<int> dp(m + 1, m + 1);
    dp[0] = 0;
    for(int j = 1; j <= m; ++j){
        set<int> s = options(j);
        for(int e: s)
            dp[j] = min(dp[j], dp[j - e] + 1);
    }
    cout << dp[m] << '\n';
}