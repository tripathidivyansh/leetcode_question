class Solution {
public:
    void Solve(int index, vector<int>&candidates, int target, vector<vector<int>>&reSult, vector<int>&path){
        if(target == 0){
            reSult.push_back(path);
            
            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }
        path.push_back(candidates[index]);
        Solve(index, candidates, target-candidates[index], reSult, path);
        path.pop_back();
        Solve(index+1, candidates, target, reSult, path);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>reSult;
        vector<int>path;

        Solve(0, candidates, target, reSult, path);
        return reSult;
    }
};