class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int i = 0; i < nums.size(); i++) {

            st.insert(nums[i]);
        }
        int len = 0, maxlen = 0, start;

        for (auto &it : st) {
            start = it - 1;
            if (st.find(it - 1) == st.end()) {
                int s = it;
                int cnt = 1;  
                while (st.find(s + 1) != st.end()) {

                    s++;
                    cnt++;
                }

                maxlen = max(maxlen, cnt);
            }
        }

        return maxlen;
    }
};
