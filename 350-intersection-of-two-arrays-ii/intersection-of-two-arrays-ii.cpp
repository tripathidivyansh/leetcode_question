class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        unordered_map<int,int>freq;
        vector<int>result;

        for(int num : nums1){
            freq[num]++;
        }
        for(int num : nums2){
            if(freq[num] > 0){
                result.push_back(num);
                freq[num]--;
            }
        }
        return result;
    }
};







// class Solution {
// public:
//     vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();

//         vector<int>result;
//         vector<bool> visited(m, false);
//         for(int i = 0; i<n; i++){
//             for(int j = 0; j<m; j++){
//                 if (!visited[j] && nums1[i] == nums2[j]){
//                     result.push_back(nums1[i]);
//                     visited[j] = true;
//                     break;
//                 }
//             }
//         }
//         return result;
//     }
// };
