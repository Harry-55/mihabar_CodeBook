#define PB push_back
#define SZ(x) ((int)(x).size())
const int MXN = 200005;   // 依題目調整，要 >= 點數

struct Dinic {
    struct Edge { int v; LL f; int re; };
    int n, s, t, level[MXN], iter[MXN];
    vector<Edge> E[MXN];
    void init(int _n, int _s, int _t) {
        n = _n; s = _s; t = _t;
        for (int i = 0; i < n; i++) E[i].clear();
    }
    void add_edge(int u, int v, LL f) {
        int a = SZ(E[u]), b = SZ(E[v]) + (u == v);
        E[u].PB({v, f, b});
        E[v].PB({u, 0, a});
    }
    bool BFS() {
        for (int i = 0; i < n; i++) level[i] = -1;
        queue<int> q; q.push(s); level[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : E[u])
                if (e.f > 0 && level[e.v] == -1) {
                    level[e.v] = level[u] + 1;
                    q.push(e.v);
                }
        }
        return level[t] != -1;
    }
    LL DFS(int u, LL nf) {
        if (u == t) return nf;
        LL res = 0;
        for (int &i = iter[u]; i < SZ(E[u]); i++) {   // current arc
            Edge &e = E[u][i];
            if (e.f > 0 && level[e.v] == level[u] + 1) {
                LL tf = DFS(e.v, min(nf, e.f));
                res += tf; nf -= tf;
                e.f -= tf; E[e.v][e.re].f += tf;
                if (nf == 0) return res;
            }
        }
        if (!res) level[u] = -1;
        return res;
    }
    LL flow() {
        LL res = 0;
        while (BFS()) {
            fill(iter, iter + n, 0);
            res += DFS(s, LLONG_MAX);
        }
        return res;
    }
} flow;
