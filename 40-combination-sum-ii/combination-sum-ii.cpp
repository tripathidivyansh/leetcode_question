class Solution {
public:
    void solve(int index,vector<int>&ds,  vector<int>& candidates, int target, vector<vector<int>>&result){
        if(target == 0){
            result.push_back(ds);
            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }
        ds.push_back(candidates[index]);
        solve(index+1, ds, candidates, target-candidates[index], result);
        ds.pop_back();
        while (index + 1 < candidates.size() && candidates[index] == candidates[index + 1]) {
            index++;
        }
        solve(index+1, ds, candidates, target, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>result;
        vector<int>ds;
        solve(0, ds, candidates, target, result);
        return result;

    }
};