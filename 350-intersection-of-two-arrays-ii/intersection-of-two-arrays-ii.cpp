class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int>result;
        vector<bool> visited(m, false);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if (!visited[j] && nums1[i] == nums2[j]){
                    result.push_back(nums1[i]);
                    visited[j] = true;
                    break;
                }
            }
        }
        return result;
    }
};