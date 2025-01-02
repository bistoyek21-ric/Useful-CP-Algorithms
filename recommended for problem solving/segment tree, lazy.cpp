#include<bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define f0 first
#define s0 second
#define pb push_back
using namespace std;

int constexpr maxn = 2e5 + 5;

int n, q;
vector<int> a;

struct node{
    pii rng = pii{0, 0};
    int val = 0;/// struct value
    int vlz = 0;/// struct lazy
    int lz = 0;/// lazy flag
};

struct segment{
    int n, N;

    const node nd;

    vector<node> bit;

    segment(int n, vector<int> &a){
        this->n = n;
        N = n << 2;
        bit.assign(N, nd);
        int ind = 0;
        build(0, n, 1, a, ind);
    }

    void ini_leaf(int u, vector<int> &a, int &ind){
        bit[u].val = a[ind++];
        return;
    }

    node mrg(node u, node v){
        node res;
        res.val = u.val + v.val;
        return res;
    }

    void upd_by_childs(int u){
        int v = u << 1;
        if((v ^ 1) < N && bit[v ^ 1].rng.s0){
            node merged = mrg(bit[v], bit[v ^ 1]);
            bit[u].val = merged.val;
        }
        else if(v < N && bit[v].rng.s0)
            bit[u].val = bit[v].val;
        return;
    }

    void build(int l, int r, int u, vector<int> &a, int &ind){
        if(r == l)
            return;
        bit[u].rng = {l, r};
        if(r - l == 1){
            ini_leaf(u, a, ind);
            return;
        }
        int mid = (l + r + 1) >> 1, v = u << 1;
        build(l, mid, v, a, ind);
        build(mid, r, v ^ 1, a, ind);
        upd_by_childs(u);
        return;
    }

    void upd_node(int u, int u_val, int flag){
        int l = bit[u].rng.f0 , r = bit[u].rng.s0;
        if(flag == 1){
            if(bit[u].lz == 2){
                bit[u].vlz += u_val;
                bit[u].val += (r - l) * u_val;
            }
            else{
                bit[u].lz = flag;
                bit[u].vlz += u_val;
                bit[u].val += (r - l) * u_val;
            }
        }
        else if(flag == 2){
            bit[u].lz = flag;
            bit[u].vlz = u_val;
            bit[u].val = (r - l) * u_val;
        }
        return;
    }

    void prop(int u){
        int v = u << 1;
        if((v ^ 1) < N && bit[v ^ 1].rng.s0){
            upd_node(v, bit[u].vlz, bit[u].lz);
            upd_node(v ^ 1, bit[u].vlz, bit[u].lz);
        }
        else if(v < N && bit[v].rng.s0)
            upd_node(v, bit[u].vlz, bit[u].lz);
        bit[u].vlz = bit[u].lz = 0;
        return;
    }

    void update(int lq, int rq, int u_val, int flag, int u = 1){
        if(N <= u)
            return;
        int l = bit[u].rng.f0 , r = bit[u].rng.s0;
        if(l == r || r <= lq || rq <= l)
            return;
        if(lq <= l && r <= rq){
            upd_node(u, u_val, flag);
            return;
        }
        if(bit[u].lz)
            prop(u);
        int v = u << 1;
        update(lq, rq, u_val, flag, v);
        update(lq, rq, u_val, flag, v ^ 1);
        upd_by_childs(u);
        return;
    }

    node query(int lq, int rq, int u = 1){
        if(N <= u)
            return {};
        int l = bit[u].rng.f0 , r = bit[u].rng.s0;
        if(l == r || r <= lq || rq <= l)
            return nd;
        if(lq <= l && r <= rq)
            return bit[u];
        if(bit[u].lz)
            prop(u);
        int v = u << 1;
        return mrg(query(lq, rq, v), query(lq, rq, v ^ 1));
    }
};

void preprocess(){
	return;
}

void give_input(){
    cin >> n >> q;
    a.assign(n, 0);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
	return;
}

void process(){
    segment tree(n, a);
    while(q--){
        char c;
        int l, r;
        cin >> c >> l >> r;
        --l;
        if(c == '1'){
            int u_val;
            cin >> u_val;
            tree.update(l, r, u_val, 1);
        }
        else if(c == '2'){
            int u_val;
            cin >> u_val;
            tree.update(l, r, u_val, 2);
        }
        else if(c == '3'){
            node res = tree.query(l, r);
            cout << res.val << '\n';
        }
    }
	return;
}

void get_output(){
	return;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0);
	int t = 1;
	//cin >> t;
	preprocess();
    while(t--){
        give_input();
        process();
        get_output();
    }
    return 0;
}
