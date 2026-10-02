const int N = 1e5 + 5;
const int INF = 1e18;
vector<pii> edge[N];
vector<int> dis(N, INF);
void dijk(int s){
    dis[s] = 0;
    vector<int> vis(N, 0);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0, s});
    while(!pq.empty()){
        int u = pq.top().ss; pq.pop();
        if(vis[u]) continue; vis[u] = 1;
        for(auto [v, w] : edge[u]){
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}