#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, mod = 998244353, inf = (1LL << 60);

int n, m, k;

vector<int> a[maxn];

//#define CLASSIC_GREEDY

#ifndef CLASSIC_GREEDY

int dp[2][maxn];

struct fenwick_tree{
     int n;

	vector<int> bit;

	void build(int n){
	    this->n = n;
	    bit.assign(n + 1, -inf);
	    return;
	}

	void update(int ind, int val){
		for(int i = ind; i < bit.size(); i += i & (-i))
			bit[i] = max(val, bit[i]);
		return;
	}

	int query(int ind){
		int mx = -inf;
		for(int i = ind; 0 < i; i -= i & (-i))
			mx = max(mx, bit[i]);
		return mx;
	}
};
#endif

void preprocess(){
	return;
}

void test_case(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        a[i] = vector<int>(3);
        cin >> a[i][0] >> a[i][1];
        #ifdef CLASSIC_GREEDY
        a[i][2] = 1;
        #else
        cin >> a[i][2];
        #endif
    }
    sort(a, a + n);
    #ifdef CLASSIC_GREEDY
    int ans = 0, r = -inf;
    for(int i = 0; i < n; ++i)
        if(r < a[i][0])
            r = a[i][1], ++ans;
    cout << ans << '\n';
    #else
    fenwick_tree fen;
    fen.build(n);
    vector<int> r;
    for(int i = 0; i < n; ++i)
        r.pb(a[i][2]);
    sort(r.begin(), r.end());
    for(int i = 0; i < n; ++i){
        dp[i][0] = (i ? max(dp[i - 1][0], dp[i - 1][1]) : 0);
        int pos = lower_bound(r.begin(), r.end(), a[i][1]) - r.begin();
        dp[i][1] = a[i][2] + max(fen.query(pos), 0LL);
        pos = lower_bound(r.begin(), r.end(), a[i][2]) - r.begin() + 1;
        fen.update(pos, dp[i][1]);
    }
    cout << max(dp[n - 1][0], dp[n - 1][1]) << '\n';
    #endif
	return;
}

void ready(){
    return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	cin >> t;
	preprocess();
    while(t--){
        test_case();
        if(t)
            ready();
    }
    return 0;
}
