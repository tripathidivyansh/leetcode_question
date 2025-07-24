class Solution {
public:
    bool solvedfS(int node, vector<bool>& visited, vector<bool>& dfSvisited, vector<vector<int>>& adj) {
        visited[node] = true;
        dfSvisited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (solvedfS(neighbour, visited, dfSvisited, adj)) {
                    return true; 
                }
            } else if (dfSvisited[neighbour]) {
                return true;  
            }
        }

        dfSvisited[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adj(V);
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        vector<bool> dfSvisited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (solvedfS(i, visited, dfSvisited, adj)) {
                    return false;  
                }
            }
        }

        return true; 
    }


};