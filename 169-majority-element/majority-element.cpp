class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ans = -1;

        for(int i = 0; i<n; i++){
            if(count == 0){
            ans = nums[i];
            count++;
            }
            else if(nums[i] == ans){
                count++;
            }else{
                count--;
            }
        }
        return ans;
    }
};