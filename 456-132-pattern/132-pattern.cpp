class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n <3) return false;

        stack<int>St;
        int maxi = INT_MIN;
        for(int i = n-1; i>= 0; i--){
            if(nums[i] < maxi) return true;
            while(!St.empty() && nums[i] > St.top()){
                maxi = St.top();
                St.pop();
            }
            St.push(nums[i]);
        }
        
        return false;
    }
};