class Solution {
public:
    void solve(int index, vector<int>&ds, vector<int>&candidates, int target, vector<vector<int>>&result){
        if(target == 0){
            result.push_back(ds);
            return;
        }
        if(target < 0 || index == candidates.size()){
            return;
        }
        ds.push_back(candidates[index]);
        solve(index, ds, candidates, target-candidates[index], result);
        ds.pop_back();
        solve(index+1, ds, candidates, target, result);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>result;

        solve(0, ds, candidates, target, result);
        return result;
    }
};