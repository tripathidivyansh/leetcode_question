class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalxor = 0;
        for(int &num : nums){

            totalxor ^=  num;
        }
        int diff = totalxor ^ k;
        return __builtin_popcount(diff);

    }

};







