#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 1e6 + 5, mod = 998244353, bs = 71, inf = (1LL << 60);

int n, m, k;

string s;

int p[maxn], ph[maxn];

int S(int x, int y){
    x = (x + mod) % mod;
    y = (y + mod) % mod;
	return (x + y) % mod;
}

int P(int x, int y){
    x = (x + mod) % mod;
    y = (y + mod) % mod;
	return (x * y) % mod;
}

int binpow(int x, int y){
	int res = 1;
	while(y){
		if(y & 1)
			res = P(res, x);
		x = P(x, x);
		y >>= 1;
	}
	return res;
}

int inv(int x){
    return binpow(x, mod - 2);
}

void preprocess(){
    p[0] = 1;
    for(int i = 1; i < maxn; ++i)
        p[i] = P(p[i - 1], bs);
    return;
}

int get_hash(int x, int y){
    if(y < x)
        return 0;
    int tmp = (x ? ph[x - 1] : 0);
    return S(ph[y], - P(tmp, p[y - x + 1]));
}

string sub(int i, int j){
    string ans = "";
    for(int k = i; k <= j; ++k)
        ans += s[k];
    return ans;
}

int binary__search(int x){
    int l = -1, r = n - x - 1;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if(get_hash(0, mid) == get_hash(x, x + mid)){
            //cout << "### " << sub(0, mid) << " == " << sub(x, x + mid) << "\n";
            l = mid;
        }
        else{
            //cout << "--- " << sub(0, mid) << " != " << sub(x, x + mid) << "\n";
            r = mid;
        }
    }
    return l;
}

void test_case(){
    cin >> s;
    n = s.size();
    ph[0] = s[0] - 'a' + 1;
    for(int i = 1; i < n; ++i)
        ph[i] = S(P(ph[i - 1], bs), s[i] - 'a' + 1);
    int len = 0;
    for(int i = 1; i < n - 1; ++i){
        int tmp = binary__search(i) + 1;
        len = max(len, tmp);
        //cout << "i = " << i << ", [" << tmp << "]\n";
    }
    //cout << "-------------------\n";
    for(int i = len - 1; ~i; --i)
        if(get_hash(0, i) == get_hash(n - i - 1, n - 1)){
            for(int j = 0; j <= i; ++j)
                cout << s[j];
            cout << '\n';
            return;
        }
        else{
            int x;
            //cout << sub(0, i) << " != " << sub(n - i - 1, n - 1) << '\n';
        }
    cout << "Just a legend\n";
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
    while(t--) {
        test_case();
        if(t)
            ready();
    }
    return 0;
}
