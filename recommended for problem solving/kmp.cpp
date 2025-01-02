#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define emp emplace_back
using namespace std;

int constexpr N = 1e6 + 9;

int n, kmp[N];

string s;

signed main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s;
	kmp[0] = 0;
	n = s.size();
	for(int i = 1; i < n; ++i){
		int tmp = kmp[i - 1];
    	while(tmp && s[i] != s[tmp])
    		tmp = kmp[tmp - 1];
    	kmp[i] = (tmp + (int)(s[i] == s[tmp]));
	}
	if(!kmp[n - 1])
		return cout << "Just a legend" << '\n', 0;
	for(int i = 0; i < n - 1; ++i)
		if(kmp[i] == kmp[n - 1]){
			for(int j = 0; j < kmp[i]; ++j)
				cout << s[j];
			cout << '\n';
			return 0;
		}
	/*cout << "/////////////" << '\n';
	for(int i = 0; i < n; ++i){
		cout << kmp[i] << " ";
	}
	cout << '\n' << "//////////////" << '\n';*/
	if(kmp[kmp[n - 1] - 1]){
		for(int i = 0; i < kmp[kmp[n - 1] - 1]; ++i)
			cout << s[i];
		cout << '\n';
	}
	else
		cout << "Just a legend" << '\n';
	return 0;
}
