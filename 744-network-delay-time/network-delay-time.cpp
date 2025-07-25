class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int V = times.size();
        vector<vector<pair<int,int>>>adj(n+1);

        vector<bool>visited(n+1,false);
        for(int i = 0; i<V; i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;;
        pq.push({0, k});
        vector<int>result(n+1, INT_MAX);
        result[k] = 0;
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            for(auto & vec : adj[node]){
                int v = vec.first;
                int wt = vec.second;
                if(d + wt < result[v]){
                    result[v] = d + wt;
                    pq.push({result[v], v});
                }
            }
        }
        int ans =  0;
        for(int i = 1; i<= n; i++){
            if(result[i] == INT_MAX) return -1;
            ans = max(ans, result[i]);
        }
        return ans;
    }
};