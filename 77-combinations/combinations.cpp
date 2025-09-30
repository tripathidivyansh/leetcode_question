class Solution {
public:
    void solve(vector<vector<int>>&ans, vector<int>& path, int start, int n, int k){
        if(k == 0){
            ans.push_back(path);

            return;
        }
        if(start > n){
            return;

        }
        path.push_back(start);
        solve(ans, path, start+1, n, k-1);
        path.pop_back();
        solve(ans, path, start+1, n, k);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>path;
        vector<vector<int>>ans;
        solve(ans,path, 1, n, k);

        return ans;
    }
};





























