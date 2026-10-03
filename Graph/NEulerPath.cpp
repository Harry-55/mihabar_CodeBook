void dfs(int u, vector<pii> edge[], vector<int> &vis){
    while(!edge[u].empty()){
        auto [v, idx] = edge[u].back(); edge[u].pop_back();
        if(vis[idx]) continue;
        vis[idx] = 1;
        dfs(v, edge, vis);
        epath.push_back(idx); // edge path
    }
    path.push_back(u); // node path
}//reverse