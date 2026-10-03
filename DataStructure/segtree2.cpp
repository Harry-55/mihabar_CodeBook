struct seg_tree{
    #define cl(x) (x << 1)
    #define cr(x) (x << 1) | 1
    vector<int> seg, arr, tag;
    int n;
    void init(int _n, const vector<int> &_arr){
        seg = vector<int>(4 * _n + 5);
        tag = vector<int>(4 * _n + 5);
        arr = _arr;
        n = _n;
        build(1, 0, _n - 1);
    }
    void pull(int id, int l, int r){
        int mid = (l+r)>>1;
        push(cl(id), l, mid);
        push(cr(id), mid + 1, r);
        seg[id] = seg[cl(id)] + seg[cr(id)];
    }
    void push(int id, int l, int r){
        if(tag[id]) {
            seg[id] += tag[id] * (r - l + 1);
            if(l != r) { 
                tag[cl(id)] += tag[id];       
                tag[cr(id)] += tag[id];
            }
            tag[id] = 0;
        }
    }
    void build(int id, int l, int r){
        if(l == r){
            seg[id] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(cl(id), l, mid);
        build(cr(id), mid + 1, r);
        pull(id, l, r);
    }
    void upd(int id, int l, int r, int sl, int sr, int v){
        push(id, l, r);
        if(sl <= l && r <= sr){
            tag[id] += v;
            return;
        }
        int mid = (l + r) >> 1;
        if(sl <= mid) upd(cl(id), l, mid, sl, sr, v);
        if(sr > mid) upd(cr(id), mid + 1, r, sl, sr, v);
        pull(id, l, r);
    }
    int query(int id, int l, int r, int sl, int sr){
        push(id, l, r);
        if(sl <= l && r <= sr){
            return seg[id];
        }
        int mid = (l + r) >> 1, res = 0;
        if(sl <= mid) res += query(cl(id), l, mid, sl, sr);
        if(mid < sr) res += query(cr(id), mid + 1, r, sl, sr);
        return res;
    }
    int query(int sl, int sr){
        return query(1, 0, n - 1, sl, sr);
    }
    void upd(int sl, int sr, int v) {
        upd(1, 0, n - 1, sl, sr, v);
    }
};
