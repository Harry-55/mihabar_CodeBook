vector<int> edge[N], deg(N, 0), ans;
bool topo(int n){
    ans.clear();
    queue<int> q;
    for(int i = 1 ; i <= n ; i++) if(deg[i] == 0) q.push(i);
    while(!q.empty()){
        int u = q.front(); q.pop();
        ans.push_back(u);
        for(auto i : edge[u]){
            if(--deg[i] == 0) q.push(i);
        }
    }
    return n == ans.size();
}
