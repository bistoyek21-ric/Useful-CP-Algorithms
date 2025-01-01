#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5;

struct fenwick_tree{

     int n;

	vector<int> bit;

	fenwick_tree(int n){
	    this->n = n;
	    bit.assign(n, 0);
	}

	void add(int ind, int val){
		for(int i = ind; i < bit.size(); i += i & (-i))
			bit[i] += val;
		return;
	}

	int ps(int ind){
		int sum = 0;
		for(int i = ind; i; i -= i & (-i))
			sum = S(sum, bit[i]);
		return sum;
	}

	int sum(int l, int r){
        return S(ps(r), -(l - 1 ? ps(l - 1) : 0));
    }
};

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
    ios::sync_with_stdio(0), cin.tie(0);
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
