const int MAXN = 200005;
vector<int> G[MAXN];
int tin[MAXN], tout[MAXN], ord[MAXN], timer_;

void flatten(int root) {
    timer_ = 0;
    vector<pair<int,int>> st = {{root, 0}};   // (節點, 父節點)
    vector<int> it(MAXN, 0);
    while (!st.empty()) {
        auto [u, p] = st.back();
        if (it[u] == 0) tin[u] = ++timer_, ord[timer_] = u;
        if (it[u] < (int)G[u].size()) {
            int v = G[u][it[u]++];
            if (v != p) st.push_back({v, u});
        } else {
            tout[u] = timer_;
            st.pop_back();
        }
    }
}
