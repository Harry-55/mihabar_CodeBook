#define SZ(x) ((int)(x).size())

struct ISAP {
    static const int MAXV = 200010;
    struct Edge { int v; LL c; int r; };
    int n, s, t;
    vector<Edge> G[MAXV];
    int iter[MAXV], d[MAXV], gap[MAXV + 1];

    void init(int _n, int _s, int _t) {        // 點編號 0 ~ n-1，自己指定 s、t
        n = _n; s = _s; t = _t;
        for (int i = 0; i < n; i++) G[i].clear();
    }
    void addEdge(int u, int v, LL c) {
        int a = SZ(G[u]), b = SZ(G[v]) + (u == v);
        G[u].push_back({v, c, b});
        G[v].push_back({u, 0, a});
    }
    LL dfs(int p, LL flow) {
        if (p == t) return flow;
        LL used = 0;
        for (int &i = iter[p]; i < SZ(G[p]); i++) {
            Edge &e = G[p][i];
            if (e.c > 0 && d[p] == d[e.v] + 1) {
                LL f = dfs(e.v, min(flow - used, e.c));
                e.c -= f; G[e.v][e.r].c += f; used += f;
                if (used == flow || d[s] >= n) return used;
            }
        }
        if (--gap[d[p]] == 0) d[s] = n;        // gap 優化
        else { d[p]++; iter[p] = 0; ++gap[d[p]]; }
        return used;
    }
    LL solve() {
        fill(iter, iter + n, 0); fill(d, d + n, 0); fill(gap, gap + n + 1, 0);
        gap[0] = n;
        LL res = 0;
        while (d[s] < n) res += dfs(s, LLONG_MAX);
        return res;
    }
} flow;
//flow.init(n, s, t);           // 點 0 ~ n-1
//flow.addEdge(u, v, cap);
//LL ans = flow.solve();
