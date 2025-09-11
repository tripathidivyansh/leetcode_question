// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         unordered_map<int, int> mp;

//         for (auto x : nums) {
//             mp[x]++;
//         }

//         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//         for (auto& x : mp) {
//             pq.push(make_pair(x.second, x.first));
//             if (pq.size() > k) {
//                 pq.pop();
//             }
//         }

//         while (!pq.empty()) {
//             ans.push_back(pq.top().second);
//             pq.pop();
//         }

//         reverse(ans.begin(), ans.end());

//         return ans;
//     }
// };


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mp;
        for (auto x : nums) {
            mp[x]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto x : mp) {
            pq.push(make_pair(x.second, x.first));
        }
        for (int i = 0; i < k; ++i) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
