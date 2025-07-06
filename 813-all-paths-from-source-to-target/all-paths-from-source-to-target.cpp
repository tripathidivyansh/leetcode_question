class Solution {
public:
    void solve(vector<vector<int>>& graph, int index, vector<vector<int>>& result, vector<int>& path) {
        path.push_back(index);
        if (index >= graph.size() - 1) {

            result.push_back(path);
        } else {
            for (int next : graph[index]) {
                solve(graph, next, result, path);
            }
        }

        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {

        vector<vector<int>> result;
        vector<int> path;
        solve(graph, 0, result, path);
        return result;
    }
};
