#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, mod = 998244353, inf = (1LL << 60);

int n, m, k;

int a[maxn];

void preprocess(){
	return;
}

void test_case(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    bool ans = false;
    int l = 0, r = n - 1;
    while(l != r){
        int sum = a[l] + a[r];
        if(sum == m){
            ans = true;
            break;
        }
        if(sum < m)
            ++l;
        else
            --r;
    }
    if(ans)
        cout << a[l] << " " << a[r] << '\n';
    else
        cout << -1 << '\n';
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
