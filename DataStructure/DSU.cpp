struct DSU {
    vector<int> f, sz;
    int cnt;
    DSU(int n) : f(n), sz(n), cnt(n) {
        for (int i = 0; i < n; i++) {
            f[i] = i;
            sz[i] = 1;
        }
    }
    int find(int x) {
        if (x == f[x]) return x;
        f[x] = find(f[x]);
        return f[x];
    }
    int merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return 0;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        f[y] = x;
        cnt--;
        return 1;
    }
    bool same(int a, int b) { return (find(a) == find(b)); }
    int group() {return cnt;}
};