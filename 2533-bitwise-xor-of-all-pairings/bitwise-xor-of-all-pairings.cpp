class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int count = 0;

        if(m%2 == 1){
            for(int i = 0; i<n; i++){
                count ^= nums1[i];
            }
        }
        if(n%2 == 1){
            for(int i = 0; i<m; i++){
                count ^= nums2[i];
            }
        }
        return count;
    }
};