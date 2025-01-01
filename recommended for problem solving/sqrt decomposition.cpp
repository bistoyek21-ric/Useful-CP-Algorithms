#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, inf = (1LL << 60);

int n, q, a[maxn], blk_sz;
vector<int> blk;

//#define MULTI_TEST
#define IOS

void preprocess(){
    blk_sz = sqrt(n);
    blk.assign((n + blk_sz - 1) / blk_sz, 0);
    for(int i = 0; i < n; ++i)
        blk[i / blk_sz] += a[i];
    return;
}

void update(int idx, int val){
    int blk_idx = idx / blk_sz;
    blk[blk_idx] += val - a[idx];
    a[idx] = val;
}

int query(int l, int r){
    int sum = 0;
    int start_blk = l / blk_sz;
    int end_blk = r / blk_sz;
    if(start_blk == end_blk){
        for(int i = l; i <= r; ++i)
            sum += a[i];
    }
    else{
        for(int i = l; i < (start_blk + 1) * blk_sz; ++i)
            sum += a[i];
        for(int i = start_blk + 1; i < end_blk; ++i)
            sum += blk[i];
        for(int i = end_blk * blk_sz; i <= r; ++i)
            sum += a[i];
    }
    return sum;
}

void test_case(){
    cin >> n >> q;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    preprocess();
    while(q--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1)
            update(l - 1, r);
        else
            cout << query(l - 1, r - 1) << '\n';
    }
    return;
}

void ready(){
    return;
}

signed main(){
    #ifdef IOS
    ios::sync_with_stdio(0), cin.tie(0);
    #endif // IOS
    int t = 1;
    #ifdef MULTI_TEST
    cin >> t;
    #endif // MULTI_TEST
    preprocess();
    while(t--){
        test_case();
        if(t)
            ready();
    }
    return 0;
}
