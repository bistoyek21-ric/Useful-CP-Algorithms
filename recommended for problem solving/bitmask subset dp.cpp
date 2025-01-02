#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5, maxp = 20, inf = (1LL << 60);

int n, m, k, mod = 998244353;

int p2[maxp], mask1[maxn], mask2[1 << maxp];

int prime[maxp] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71};

//#define MULTI_TEST
#define IOS

void preprocess(){
    p2[0] = 1;
    for(int i = 1; i < maxp; ++i)
        p2[i] = 2 * p2[i - 1];
	return;
}

__int128 read_int128(){
    string s;
    cin >> s;
    __int128 res = 0;
    bool neg = false;
    int start = 0;
    if(s[0] == '-'){
        neg = true;
        start = 1;
    }
    for(int i = start; i < s.size(); ++i)
        res = res * 10 + (s[i] - '0');
    return neg ? -res : res;
}

void test_case(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        __int128 num = read_int128();;
        mask1[i] = 0;
        for(int j = 0; j < maxp; ++j)
            if(!(num % prime[j]))
                mask1[i] |= p2[j];
        ++mask2[mask1[i]];
    }
    int sz = (p2[maxp - 1] << 1);
    for(int i = 1; i < sz; ++i){
        int j = 0;
        while(true){
            if(i & p2[j])
                break;
            ++j;
        }
        int k = maxp - 1;
        while(true){
            if(i & p2[k])
                break;
            --k;
        }
        if(k == j){
            mask2[i] += mask2[0];
            continue;
        }
        mask2[i] += mask2[i ^ p2[j]] + mask2[i ^ p2[k]] - mask2[i ^ p2[j] ^ p2[k]];
    }
    int ans = 0;
    sz -= 1;
    for(int i = 0; i < n; ++i)
        if(!mask1[i])
            ans += n - 1;
        else
            ans += mask2[sz ^ mask1[i]];
    cout << ans / 2 << '\n';
	return;
}

void ready(){
    memset(mask2, 0, sizeof(mask2));
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
/*
#include <iostream>
#include <vector>
#include <cmath>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> p2(20);
    p2[0] = 1;
    for(int i = 1; i < 20; ++i)
        p2[i] = 2 * p2[i - 1];
    int prime[19] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
    std::vector<int> mask1(n, 0);
    std::vector<int> mask2(p2[19], 0);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        for (int j = 0; j < 19; ++j) {
            if (a[i] % prime[j] == 0) {
                mask1[i] += p2[j];
            }
        }
        mask2[mask1[i]] += 1;
    }
    for (int i = 1; i < p2[19]; ++i) {
        int j = 0;
        while (true) {
            if (i & p2[j] != 0) {
                break;
            }
            ++j;
        }
        int k = 19;
        while (true) {
            if (i & p2[k] != 0) {
                break;
            }
            --k;
        }
        if (k == j) {
            mask2[i] += mask2[0];
            continue;
        }
        mask2[i] += mask2[i ^ p2[j]] + mask2[i ^ p2[k]] - mask2[i ^ p2[j] ^ p2[k]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 1) {
            ans += n - 1;
        } else {
            ans += mask2[p2[19] - mask1[i] - 1];
        }
    }
    std::cout << ans / 2 << std::endl;
    return 0;
}
*/
