class Solution {
public:
    int countEdges(vector<vector<int>>& adj) {
        int n = (int) adj.size();
        int cnt_edges = 0;
        for (int u = 0; u < n; u++) {
            for (int v : adj[u]) {
                cnt_edges++;
            }
        }
        return cnt_edges / 2;
    }
};
