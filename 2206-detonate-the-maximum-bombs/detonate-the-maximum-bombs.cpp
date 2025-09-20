class Solution {
public:
    void dfS(int u, unordered_set<int>& viSited, vector<vector<int>>& adj) {
        viSited.insert(u);
        for (int v : adj[u]) {
            if (viSited.find(v) == viSited.end()) {
                dfS(v, viSited, adj);
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0];
                long long y2 = bombs[j][1];

                long long dx = x2 - x1;
                long long dy = y2 - y1;
                long long distSq = dx * dx + dy * dy;

                if (r1 * r1 >= distSq) {
                    adj[i].push_back(j);
                }
            }
        }

        int reSult = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> viSited;
            dfS(i, viSited, adj);
            reSult = max(reSult, (int)viSited.size());
        }

        return reSult;
    }
};
