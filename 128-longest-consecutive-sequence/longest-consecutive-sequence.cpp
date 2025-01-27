class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int>s;
        for(int i = 0; i<n; i++){
            s.insert(nums[i]);
        }
        int count = 0;
        int maxi = 0;
        for(auto malik : s){
            if(s.find(malik-1) == s.end()){
                int currnum = malik;
                count = 1;
                while(s.find(currnum + 1) != s.end()){
                    currnum++;
                    count++;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};