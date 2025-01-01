#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 10, mod = 1e9 + 7;

int S(int x, int y){
	return (((x + y) % mod) + mod) % mod;
}

int P(int x, int y){
	return (((x * y) % mod) + mod) % mod;
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

void preprocess(){
    return;
}

void give_input(){
    return;
}

void process(){
    return;
}

void get_output(){
    return;
}

signed main(){
	ios::sync_with_stdio(false), cin.tie(nullptr);
    int t = 1;
    cin >> t;
    preprocess();
    while(t--){
        give_input();
        process();
        get_output();
    }
    return 0;
}
