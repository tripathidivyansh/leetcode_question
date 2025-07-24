class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>>adj(V);
        vector<int>indgree(V, 0);
        for(int i = 0; i<prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
            indgree[u]++;
        }
        queue<int>q;
        for(int i = 0; i<V; i++){
            if(indgree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int neighbour : adj[node]){
                indgree[neighbour]--;
                if(indgree[neighbour] == 0){
                    q.push(neighbour);
                }
            }
        }
        if(ans.size() != numCourses) return {};
        return ans;
    }
};