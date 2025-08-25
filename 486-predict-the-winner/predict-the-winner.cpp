class Solution {
public:
    int Solve(int i, int j, vector<int>&nums){
        if(i == j) return nums[i];
        int leftpick = nums[i] - Solve(i+1, j, nums);
        
        int rightpick = nums[j] - Solve(i, j-1, nums);
        int maxi = max(leftpick, rightpick);
        return maxi;
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int Score =  Solve(0, n-1, nums);
        if(Score >= 0){
            return true;
        }else{
            
            return false;
        }
    }
};
