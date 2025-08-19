class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while(l< r){

            int total = numbers[l] + numbers[r];
            if(total == target){
                return {l+1, r+1};
            }else if(total > target){
                r--;
            }else{
                l++;
            }
        }
        return {-1, -1};
    }
};