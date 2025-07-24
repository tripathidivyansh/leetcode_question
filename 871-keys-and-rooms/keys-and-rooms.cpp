class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int V = rooms.size();
        vector<bool>visited(V, false);
        
        queue<int>q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int neighbour : rooms[node]){
                if(!visited[neighbour]){
                    visited[neighbour] = true;
                    q.push(neighbour);
                }
            }
        }
        for(bool v : visited){
            if(!v) return false;
        }
        return true;
    }
};