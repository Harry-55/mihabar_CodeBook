int vis[], suc[];
int dfs(int x, int v) { //v -> x 是 tree edge
    if (vis[x]) return x;
    suc[x] = v; //紀錄 x 的父節點 v
    vis[x] = 1;
    for (auto i : edge[x]) {
        if (i == v) continue;
        int tmp = dfs(i, x); // x 的祖先，
        if (tmp) {
            int now = x;
            vector<int> ans;
            ans.push_back(i);
            while (now != tmp) { //找從x到tmp的路徑
                ans.push_back(now);
                now = suc[now];
            }
            ans.push_back(i);
            for (auto v : ans) cout << v << " ";
            cout << "\n";
            exit(0);
        }
    }
    return 0;
}