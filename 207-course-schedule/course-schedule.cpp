class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);

        vector<int> indegree(V, 0);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indegree[u]++;
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (int neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0) {
                    q.push(neighbour);
                }
            }

        }
        return count == numCourses;

    }
};