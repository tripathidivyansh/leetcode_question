class Solution {
public:
    void Solve(int index, vector<int>& candidates, int target, vector<vector<int>>&reSult, vector<int>&path){
        if(target == 0){
            reSult.push_back(path);

            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }
        path.push_back(candidates[index]);
        Solve(index+1, candidates, target-candidates[index], reSult, path);
        while(index+1 < candidates.size() && candidates[index] == candidates[index+1]){
            index++;
        }

        path.pop_back();
        Solve(index+1, candidates, target, reSult, path);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>reSult;
        vector<int>path;
        sort(candidates.begin(), candidates.end());
        Solve(0, candidates, target, reSult, path);
        return reSult;
    }
};




