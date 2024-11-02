class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        unordered_set<int>setA;
        unordered_set<int> resultSet;

        for(int i = 0; i<n; i++){
            setA.insert(nums1[i]);
        }
        for(int i =0; i<m; i++){
            if(setA.find(nums2[i]) != setA.end()){
                resultSet.insert(nums2[i]);
            }
        }
         return vector<int>(resultSet.begin(), resultSet.end());
    }
};