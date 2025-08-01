class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>reS(n, 1);

        for(int i = 1; i<n; i++){
            reS[i] = reS[i-1] * nums[i-1];
        }
        int postfix = 1;
        for(int i = n-1; i>= 0; i--){
            reS[i] *= postfix;
            postfix *= nums[i];
        }
        return reS;
    }
    
};