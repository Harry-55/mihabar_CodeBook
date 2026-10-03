void dfs(int u){
    vis[u] = 1;                 
    for (auto i : edge[u]) {
        if (vis[i] == 1) {
            vector<int> ans;
            ans.push_back(i);
            int now = u;
            while (now != i) {
                ans.push_back(now);
                now = suc[now];
            }
            ans.push_back(i);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto i : ans) cout << i << " ";
            exit(0);
        }
        if (vis[i] == 0) {
            suc[i] = u;
            dfs(i);
        }
    }
    vis[u] = 2;
}