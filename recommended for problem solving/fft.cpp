#include <bits/stdc++.h>
#define int long long
using namespace std;

int constexpr mod = 1000000000;

map<int, int> M;

int f(int n){
    if(n == 0)
        return 1;
    int ans = M[n];
    if(ans)
        return ans;
    int m = (n + 1) / 2;
    for(int i = 1; i < 10; ++i)
        for(int k = 1; k <= i; ++k)
            if(min(n - m - i + k, m - k) >= 0)
                ans = (ans + (f(m - k) * f(n - m - i + k)) % mod) % mod;
    M[n] = ans;
    return ans;
}

signed main(){
    int ans = 0, n = 1;
    for(int i = 1; i < mod; ++i){
        int num = i, sum = 0;
        bool b = true;
        while(num && b){
            b = (num % 10);
            sum += num % 10;
            num /= 10;
        }
        if(sum != 13 || !b)
            continue;
        ans = (ans + i) % mod;
    }
    for(int i = 0; i < 17; ++i)
        n *= 13;
    for(int i = 17; i; --i){
        for(int j = 100'000'000; j < mod; ++j){
            bool b = true;
            int num = j, sum = 0;
            while(num && b){
                b = (num % 10);
                sum += num % 10;
                num /= 10;
            }
            if(sum >= n || !b)
                continue;
            ans = (ans + (f(n - sum) * j) % mod) % mod;
        }
        n /= 13;
    }
    cout << ans << '\n';
    return 0;
}
