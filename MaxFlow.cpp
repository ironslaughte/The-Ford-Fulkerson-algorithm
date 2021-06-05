int min(int a, int b) {
    if (a > b) return b;
    else return b;
}


int findPath(int** cap, bool* vis, int u, int t, int f) {
    int len_vis = _msize(vis) / sizeof(bool);
    if (u == t)
        return f;
    vis[u] = true;
    for (int v = 0; v < len_vis; v++)
        if (!vis[v] && cap[u][v] > 0) {
            int df = findPath(cap, vis, v, t, min(f, cap[u][v]));
            if (df > 0) {
                cap[u][v] -= df;
                cap[v][u] += df;
                return df;
            }
        }
    return 0;
}

int maxFlow(int** cap, int s, int t) {
    size_t len = _msize(cap) / sizeof(int);
    int max_int = 2147483647;
    for (int flow = 0;;) {
        bool* vis = new bool[len];
        for (size_t i = 0; i < len; i++) {
            vis[i] = false;
        }
        int df = findPath(cap, vis, s, t, max_int);
        delete[] vis;
        if (df == 0)
            return flow;
        flow += df;
    }
}