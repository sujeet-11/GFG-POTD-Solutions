//  DFS
class Solution {
private:
  vector<bool> vis;
  bool dfs(int u, int dest, vector<vector<int>>& adj) {
    vis[u] = true;
    if (u == dest) {
      return true;
    }
    for (int v : adj[u]) {
      if (!vis[v]) {
        if (dfs(v, dest, adj)) {
          return true;
        }
      }
    }
    return false;
  }
public:
  bool checkPath(vector<vector<int>> &adj, int u, int v) {
    int n = (int) adj.size();
    vis.assign(n, false);
    return dfs(u, v, adj);
  }
};


// DSU
struct DSU {
  vector<int> parent;
  vector<int> sz;
  DSU(int n) {
    parent.resize(n);
    iota(parent.begin(), parent.end(), 0);
    sz.assign(n, 1);
  }
  int find(int u) {
    if (parent[u] == u) {
      return u;
    }
    return parent[u] = find(parent[u]);
  }
  void unite(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
      return;
    }
    if (sz[u] < sz[v]) {
      swap(u, v);
    }
    parent[v] = u;
    sz[u] += sz[v];
  }
};
class Solution {
public:
  bool checkPath(vector<vector<int>> &adj, int u, int v) {
    int n = (int) adj.size();
    DSU dsu(n);
    for (int u = 0; u < n; u++) {
      for (int v : adj[u]) {
        dsu.unite(u, v);
      }
    }
    return dsu.find(u) == dsu.find(v);
  }
};
