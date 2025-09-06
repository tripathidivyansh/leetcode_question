// class Solution {
// public:
//     vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
//         vector<vector<int>> pairs;
        
        
//         for (int i = 0; i < nums1.size(); i++) {
//             for (int j = 0; j < nums2.size(); j++) {
//                 pairs.push_back({nums1[i], nums2[j]});
//             }
//         }

        
//         sort(pairs.begin(), pairs.end(), [](const vector<int>& a, const vector<int>& b) {
//             return a[0] + a[1] < b[0] + b[1];
//         });

        
//         if (k > pairs.size()) k = pairs.size();
//         pairs.resize(k);

//         return pairs;
//     }
// };









class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int n = nums1.size(), m = nums2.size();
        if (n == 0 || m == 0) return ans;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for (int i = 0; i < n && i < k; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while (k-- > 0 && !pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int sum = cur[0], i = cur[1], j = cur[2];
            ans.push_back({nums1[i], nums2[j]});

            if (j + 1 < m) {
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }
        return ans;
    }
};








































