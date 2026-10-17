bool dfs(int u) {  // 找最大匹配
    for (int &v : g[u]) {
        if (vis[v]) continue; // 有連通且未拜訪
        vis[v] = true;
        if (S[v] == -1 || dfs(S[v])) {  
            S[v] = u;    // 紀錄匹配
            return true; // 反轉匹配邊以及未匹配邊的狀態
        }
    }
    return false;
}
ans = 0; // 記得每次使用需清空 vis，S 初始化為 -1
for (int i = 1; i <= n; i++) {  // 跑左集合
    memset(vis, 0, sizeof(vis));
    if (dfs(i)) ans++;
}// 找二分圖最大匹配