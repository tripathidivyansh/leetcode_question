class Solution {
public:
    string frequencySort(string s) {
        
        int n = s.size();
        string ans;
        unordered_map<char, int> mp;
        for (auto x : s) {
            mp[x]++;
        }
        priority_queue<pair<int, char>> pq;
        for (auto x : mp) {
            pq.push(make_pair(x.second, x.first));
        }
        while (!pq.empty()) {
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            for (int i = 0; i < freq; i++) {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};




