#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 505, inf = (1LL << 60);

int n, N, q, mod = 998244353;

vector<int> rect[maxn], query[maxn];

int dist[maxn][maxn];

//#define MULTI_TEST
#define IOS

void preprocess(){
	return;
}

int find_dist(int i, int j){
    if(i == j)
        return (int)(N <= i);
    int d_h = 0, d_w = 0;
    if(rect[i][2] <= rect[j][0])
        d_h = rect[j][0] - rect[i][2];
    else
        d_h = rect[i][0] - rect[j][2];
    if(rect[i][3] <= rect[j][1])
        d_w = rect[j][1] - rect[i][3];
    else
        d_w = rect[i][1] - rect[j][3];
    d_h = max(d_h, 0LL);
    d_w = max(d_w, 0LL);
    return d_h + d_w + (int)(N <= i) + (int)(N <= j) - 1;
}

int find_rect(vector<int> cor){
    for(int i = 0; i < n; ++i)
        if(rect[i][0] <= cor[0] && cor[0] <= rect[i][2] && rect[i][1] <= cor[1] && cor[1] <= rect[i][3])
            return i;
    return -1;
}

void test_case(){
    int H, W;
    cin >> H >> W >> n;
    N = n;
    for(int i = 0; i < n; ++i){
        rect[i] = vector<int>(4);
        for(int j = 0; j < 4; ++j)
            cin >> rect[i][j];
    }
    cin >> q;
    for(int i = 0; i < q; ++i){
        vector<int> p[2];
        query[i] = vector<int>(2);
        for(int j = 0; j < 2; ++j){
            p[j] = vector<int>(2);
            for(int k = 0; k < 2; ++k)
                cin >> p[j][k];
        }
        for(int j = 0; j < 2; ++j){
            query[i][j] = find_rect(p[j]);
            if(query[i][j] == -1){
                rect[n] = {p[j][0], p[j][1], p[j][0], p[j][1]};
                query[i][j] = n;
                ++n;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            dist[i][j] = find_dist(i, j);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            for(int k = 0; k < n; ++k)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k] - (int)(N <= i));
    for(int i = 0; i < q; ++i)
        cout << dist[query[i][0]][query[i][1]] << '\n';
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
