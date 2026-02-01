struct Seg {
    int n;
    struct Node { 
        int mn, mx, lazy;
    };
    vector<Node> t;

    Seg(vector<int> &a){
        n = a.size();
        t.assign(4*n, {INT_MAX, INT_MIN, 0});
        build(1, 0, n-1, a);
    }

    void build(int v, int l, int r, const vector<int> &a){
        if(l == r) {
            t[v].mn = t[v].mx = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(v*2, l, m, a);
        build(v*2+1, m+1, r, a);
        pull(v);
    }

    void pull(int v){
        t[v].mn = min(t[v*2].mn, t[v*2+1].mn);
        t[v].mx = max(t[v*2].mx, t[v*2+1].mx);
    }

    void apply_add(int v, int x){
        t[v].mn += x;
        t[v].mx += x;
        t[v].lazy += x;
    }

    void push(int v){
        if(t[v].lazy){
            apply_add(v*2, t[v].lazy);
            apply_add(v*2+1, t[v].lazy);
            t[v].lazy = 0;
        }
    }

    void add_range(int v, int l, int r, int ql, int qr, int x){
        if(ql > r || qr < l) return;
        if(ql <= l && r <= qr) {
            apply_add(v, x);
            return;
        }
        push(v);
        int m = (l + r) / 2;
        add_range(v*2, l, m, ql, qr, x);
        add_range(v*2+1, m+1, r, ql, qr, x);
        pull(v);
    }

    void add_range(int l, int r, int x){
        add_range(1, 0, n-1, l, r, x);
    }

    int find_rightmost_zero(int v, int l, int r){
        if(t[v].mn > 0 || t[v].mx < 0) return -1;
        if(l == r){
            return l;
        }
        push(v);
        int m = (l + r) / 2;
        int res = find_rightmost_zero(v*2+1, m+1, r);
        if(res != -1) return res;
        return find_rightmost_zero(v*2, l, m);
    }

    int find_rightmost_zero(){
        return find_rightmost_zero(1, 0, n-1);
    }
};
