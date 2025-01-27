class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        vector<int>ans1;
        vector<int>ans2;
        for(int i = 0; i<n; i++){
            if(nums[i] < 0){
                ans.push_back(nums[i]);
            }else{
                ans1.push_back(nums[i]);
            }
        }
        int i = 0, j = 0;
        while( j < ans1.size() && i < ans.size()){
            ans2.push_back(ans1[j]);
            ans2.push_back(ans[i]);
            j++;
            i++;
        }
        while(j < ans1.size()){
            ans2.push_back(ans1[j]);
            j++;
        }
        while(i < ans.size()){
            ans2.push_back(ans[i]);
            i++;
        }
        return ans2;
    }
};