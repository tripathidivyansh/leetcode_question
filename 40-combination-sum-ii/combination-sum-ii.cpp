class Solution {
public:

    void solve(vector<int>&candidates, int index, int target, vector<int>&path, vector<vector<int>>&result){
        if(target == 0){

            result.push_back(path);
            return;
        }
        if(target < 0 || index >=candidates.size()){
            return;
        }
        path.push_back(candidates[index]);
        solve(candidates, index+1, target - candidates[index], path, result);
        while(index+ 1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }
        path.pop_back();
        solve(candidates, index+1, target, path, result);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>path;

        sort(candidates.begin(), candidates.end());
        solve(candidates, 0, target, path, result);
        return result;
    }
};