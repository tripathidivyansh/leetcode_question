class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0, Streak = 0;

        for(int x : nums){
            if(x == 0){
                Streak++;
                ans += Streak;
            }else{
                Streak = 0;
            }
        }

        return ans;
    }
};



