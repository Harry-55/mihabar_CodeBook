void bfs_01(int s, int n) {
    for(int i = 1; i <= n; i++) dis[i] = INF;
    deque<int> dq;
    dis[s] = 0;
    dq.push_front(s);
    while(!dq.empty()) {
        int u = dq.front();dq.pop_front();
        for(auto [v, w] : edge[u]) {
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
}