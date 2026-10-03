struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {return w < other.w;}
};
int kruskal(int n, vector<Edge>& edges) {
    dsu.init(n);
    sort(edges.begin(), edges.end());
    int mst_weight = 0;
    int edge_cnt = 0;
    for (auto e : edges) {
        if (dsu.merge(e.u, e.v)) {
            mst_weight += e.w;
            edge_cnt++;
            if (edge_cnt == n - 1) break;
        }
    }
    if (edge_cnt < n - 1) return -1;
    return mst_weight;
}