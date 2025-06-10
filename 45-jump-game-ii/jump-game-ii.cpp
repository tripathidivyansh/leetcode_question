class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<= 1){
            return 0;
        }
        int jumpS = 0, curr = 0,next = 0;
        for(int i = 0; i<n-1; i++){
            next = max(next, i+nums[i]);

            if(i == curr){
                jumpS++;
                curr = next;
            }
        }
        return jumpS;
    }
};