class Solution {
public:
    void dfS(int i, vector<vector<int>>& adj, vector<int>& viS) {
        viS[i] = 1;
        for (auto it : adj[i]) {
            if (!viS[it]) {
                dfS(it, adj, viS);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }

            }
        }
        vector<int> viS(V, 0);
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!viS[i]) {
                count++;
                dfS(i, adj, viS);
            }
        }
        return count;
    }
};








