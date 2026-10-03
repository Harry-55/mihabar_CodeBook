int vis[N] = {0};
bool dfs(int u) {
    if (vis[u] == 1) return true;
    if (vis[u] == 2) return false;
    vis[u] = 1;
    for (auto v : edge[u]) {
        if (dfs(v)) {
            return true;
        }
    }
    vis[u] = 2;
    return false;
}//有向圖找環
bool dfs(int x, int v) {
    if (vis[x]) return true;
    vis[x] = 1;
    for (auto i : edge[x]) {
        if (i == v) continue;
        if (dfs(i, x)) return true;
    }
    return false;
}//無向圖找環