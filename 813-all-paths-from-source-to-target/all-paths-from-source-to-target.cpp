class Solution {
public:
    void solve(int index, vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&result){
        path.push_back(index);
        if(index >= graph.size()-1){
            result.push_back(path);   
        }else{
            for(int next : graph[index]){
                solve(next, graph, path, result);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        vector<vector<int>>result;
        solve(0, graph, path, result);
        return result;
    }
};