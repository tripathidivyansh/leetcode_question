class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);  

        for (int Start = 0; Start < V; Start++) {
            if (color[Start] == -1) {  
                queue<int> q;
                q.push(Start);

                color[Start] = 0;
                while (!q.empty()) {
                    int node = q.front();
                    q.pop();
                    for (auto it : graph[node]) {
                        if (color[it] == -1) {
                            color[it] = !color[node];
                            q.push(it);
                        } else if (color[it] == color[node]) {
                            return false;

                        }
                    }
                }
            }
        }
        return true;
    }
};
























