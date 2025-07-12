class Solution {
public:

    void solve(int index, vector<int>&ds, int k, int n, vector<vector<int>>&result){
        if(ds.size() == k && n == 0){
            result.push_back(ds);
            return;
        }
        if(ds.size() > k || k < 0){
            return;
        }
        for(int i = index; i<=9; i++){
            ds.push_back(i);
            solve(i+1, ds, k, n-i, result);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ds;
        vector<vector<int>>result;
        solve(1, ds, k,  n, result);
        return result;
    }
};