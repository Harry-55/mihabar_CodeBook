struct seg_tree{
    #define cl(x) (x << 1)
    #define cr(x) (x << 1) | 1
    vi seg, arr;
    int n;
    void init(int _n, vi &_arr){
        seg = vi(4 * _n + 5);
        arr = _arr;
        n = _n;
        build(1, 0, _n - 1);
    }
    void pull(int id){
        // 修改條件
        seg[id] = min(seg[cl(id)], seg[cr(id)]);
    }
    void build(int id, int l, int r){
        if(l == r){
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cl(id), l, mid);
        build(cr(id), mid + 1, r);
        pull(id);
    }
    void upd(int id, int l, int r, int x, int v){
        if(l == r){
            seg[id] = v;
            return;
        }
        int mid = (l + r) >> 1;
        if(x <= mid) upd(cl(id), l, mid, x, v);
        else upd(cr(id), mid + 1, r, x, v);
        pull(id);
    }
    int query(int id, int l, int r, int sl, int sr){
        if(sl <= l && r <= sr){
            return seg[id];
        }
        int mid = (l + r) >> 1, res = INF;
        if(sl <= mid) res = min(res, query(cl(id), l, mid, sl, sr));
        if(mid < sr) res = min(res, query(cr(id), mid + 1, r, sl, sr));
        return res;
    }
    int find_first(int id, int l, int r, int sl, int sr, int k){//二分搜
        if(l > sr || r < sl || seg[id] > k) return -1;
        if(l == r) return l;
        int mid = (l + r) >> 1;
        int res = find_first(cl(id), l, mid, sl, sr, k);
        if(res == -1) res = find_first(cr(id), mid + 1, r, sl, sr, k);
        return res;
    }
    int find_first(int l, int r, int k) {
        return find_first(1, 0, n - 1, l, r, k);
    }
    int query(int sl, int sr){
        return query(1, 0, n - 1, sl, sr);
    }
    void upd(int x, int v){
        upd(1, 0, n - 1, x, v);
    };
};