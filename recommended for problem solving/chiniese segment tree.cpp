#include <bits/stdc++.h>
#define int long long
using namespace std;

int constexpr maxp = 24, maxn = (1 << maxp);

int tr[maxn << 1], a[maxn];

void update(int ind, int delta){
	int cur = ind + maxn;
	while(cur){
		tr[cur] += delta;
		cur >>= 2;
	}
	return;
}

int sum(int l, int r){
	auto f = [&](int n){
		int res = 0, num = 1;
		while(true){
			if(n % num)
				return res - 1;
			num <<= 1;
			++res;
		}
		return -1LL;
	};

	l += maxn, r += maxn;
	int res = 0;
	do{
		int k = f(l);
		while(r < l + (1 << k))
			--k;
		res += tr[l >> k];
		l += (1 << k);
	} while(l != r);
	return res;
}

int add_then_update(int ind){
	auto g = [&](int ind){
		return ind + 1 - sum(0, ind + 1);
	};

	int e, b, l, r, k = g(ind);
	l = 0, r = ind;
	while(r - l != 1){
		int mid = (l + r) / 2;
		if(k != g(mid))
			l = mid;
		else
			r = mid;
	}
	b = r;
	l = ind, r = maxn - 1;
	while(r - l != 1){
		int mid = (l + r) / 2;
		if(k != g(mid))
			r = mid;
		else
			l = mid;
	}
	e = r;
	update(b + e - ind, -1);
	update(b, 1);
	update(e, 1);
	return (ind - b) * (e - ind);
}

signed main(){
	int ini = (maxn / 2) - 750, jomle = 123456;
	int N = 1500;
	cin >> N;
	for(int i = ini; i < ini + N; ++i){
		if(jomle % 2){
			jomle /= 2;
			jomle ^= 926252;
		}
		else
			jomle /= 2;
		a[i] = jomle % 2048 + 1;
	}
	int ans = 0;
	for(int i = ini; i < ini + N; ++i)
		while(a[i]--){
			if(sum(i, i + 1))
				ans += add_then_update(i);
			else
				update(i, 1);
		}
	cout << ans << '\n';
	return 0;
}
