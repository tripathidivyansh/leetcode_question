class Solution {
public:

    void solve(int n, int k, int index, vector<vector<int>>&ans, vector<int>&path){
        if(path.size() == k){
            ans.push_back(path);
            return;
        }
        for(int i = index; i<=n; i++){
            path.push_back(i);
            solve(n, k, i+1, ans, path);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>path;

        solve(n, k, 1, ans, path);
        return ans;
    }
};