#include<bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxn = 1e7 + 9, inf  = (1LL << 60);

int a[maxn], l[maxn], r[maxn];

vector<int> min_stack;

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n, ans, t;
    //cin >> t;
    while(cin >> n && n){
        ans = 0;
        for(int i = 1; i <= n; ++i)
            cin >> a[i];
        a[0] = a[n + 1] = -inf;
        min_stack.push_back(0);
        for(int i = 1; i <= n; ++i){
            while(a[i] <= a[min_stack.back()])
                min_stack.pop_back();
            l[i] = min_stack.back();
            min_stack.push_back(i);
        }
        min_stack.clear();
        min_stack.push_back(n + 1);
        for(int i = n; i; --i){
            while(a[i] <= a[min_stack.back()])
                min_stack.pop_back();
            r[i] = min_stack.back();
            ans = max(ans, (r[i] - l[i] - 1) * a[i]);
            min_stack.push_back(i);
        }
        cout << ans << '\n';
    }
    return 0;
}
