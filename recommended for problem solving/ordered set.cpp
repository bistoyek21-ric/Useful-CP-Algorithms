#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int constexpr N = 1e6 + 3;

bool b;

int n, m, ans, a[N], A[N], A1[N];

ordered_set<int> S;

void get_input(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    return;
}

void process(){
    for(int i = n - 1; i >= 0; --i){
        A[i] = S.order_of_key(a[i]);
        S.insert(a[i]);
    }
    S.clear();
    for(int i = 0; i < n; ++i){
        A1[i] = S.size() - S.order_of_key(a[i]);
        ans += A1[i] * A[i];
        S.insert(a[i]);
    }
    return;
}

void give_output(){
    cout << ans << '\n';
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--){
        get_input();
        process();
        give_output();
    }
    return 0;
}
