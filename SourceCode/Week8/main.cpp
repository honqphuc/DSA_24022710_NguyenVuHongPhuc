#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1, 1);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

int kruskal(int n, vector<Edge> edges) {
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a.w < b.w; });

    DSU dsu(n);
    int mst_weight = 0;

    for (auto &e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
        }
    }
    return mst_weight;
}

int prim(int n, vector<vector<pair<int,int>>> &adj, int start = 1) {
    vector<bool> visited(n+1, false);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    pq.push({0, start});
    int mst_weight = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (visited[u]) continue;

        visited[u] = true;
        mst_weight += w;

        for (auto &[w2, v] : adj[u]) {
            if (!visited[v]) pq.push({w2, v});
        }
    }

    return mst_weight;
}

vector<int> dijkstra(int n, vector<vector<pair<int,int>>> &adj, int start) {
    const int INF = 1e9;
    vector<int> dist(n+1, INF);

    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;

        for (auto &[w, v] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<vector<pair<int,int>>> adj(n+1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    cout << " Kruskal MST \n";
    cout << "Tong trong so = " << kruskal(n, edges) << "\n\n";

    cout << " Prim MST \n";
    cout << "Tong trong so = " << prim(n, adj, 1) << "\n\n";

    cout << " Dijkstra tu dinh 1 \n";
    vector<int> dist = dijkstra(n, adj, 1);
    for (int i = 1; i <= n; i++)
        cout << "dist[1 -> " << i << "] = " << dist[i] << "\n";

    return 0;
}
