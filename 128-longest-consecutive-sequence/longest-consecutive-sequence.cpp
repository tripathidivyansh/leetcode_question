class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        int maxi = 1;
        if(n==0){
            return 0;
        }
        set<int>s;
        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }
        for(auto malik : s){
            if(s.find(malik-1) == s.end()){
                int count = 0;
                while(s.find(malik++) != s.end()){
                    count++;
                }
                maxi = max(maxi, count);
            }

        }
        return maxi;
    }   
};