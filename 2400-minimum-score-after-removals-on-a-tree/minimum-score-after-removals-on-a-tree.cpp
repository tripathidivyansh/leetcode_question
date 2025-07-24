class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> xorSubtree(n), parent(n, -1);
        function<void(int, int)> dfs = [&](int u, int par) {
            xorSubtree[u] = nums[u];
            parent[u] = par;
            for (int v : adj[u]) {
                if (v == par) continue;
                dfs(v, u);
                xorSubtree[u] ^= xorSubtree[v];
            }
        };
        dfs(0, -1);
        int totalXOR = xorSubtree[0];
        int minScore = INT_MAX;

        for (int i = 1; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int a = i, b = j;

                if (isAncestor(a, b, parent)) {
                    int x = xorSubtree[b];
                    int y = xorSubtree[a] ^ xorSubtree[b];
                    int z = totalXOR ^ xorSubtree[a];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else if (isAncestor(b, a, parent)) {
                    int x = xorSubtree[a];
                    int y = xorSubtree[b] ^ xorSubtree[a];
                    int z = totalXOR ^ xorSubtree[b];
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                } else {
                    int x = xorSubtree[a];
                    int y = xorSubtree[b];
                    int z = totalXOR ^ x ^ y;
                    minScore = min(minScore, max({x, y, z}) - min({x, y, z}));
                }
            }
        }
        return minScore;
    }
    bool isAncestor(int u, int v, const vector<int>& parent) {
        while (v != -1) {
            if (v == u) return true;
            v = parent[v];
        }
        return false;
    }
};