class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1; 
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int miniI = 0;
        int maxiI = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] < mini){
                mini = nums[i];
                miniI = i;
            }
            if(nums[i] > maxi){
                maxi = nums[i];
                maxiI = i;
            }
        }
        int left = max(miniI, maxiI) + 1;
        int right = n - min(miniI, maxiI);
        int bothSides = min(miniI, maxiI) + 1 + (n - max(miniI, maxiI));

        return min({left, right, bothSides});
    }
};
