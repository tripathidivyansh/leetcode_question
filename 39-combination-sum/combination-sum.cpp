class Solution {
public:

    void solve(int index, vector<vector<int>>&ans,vector<int>&candidates,  int target, vector<int>&temp){
        if(target == 0){

            ans.push_back(temp);
            return;
        }
        if(target < 0 || index >= candidates.size()){
            return;
        }
        temp.push_back(candidates[index]);
        solve(index, ans, candidates, target-candidates[index], temp);
        temp.pop_back();
        solve(index+1, ans, candidates, target, temp);
    }   
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;

        solve(0, ans, candidates, target, temp);
        return ans;
    }
};