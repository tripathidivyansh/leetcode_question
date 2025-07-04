class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen = 0, l = 0, r = 0;
        vector<int> freq(256, 0);

        while (r < s.size()) {
            freq[s[r]]++;
            while (freq[s[r]] > 1) {
                freq[s[l]]--;
                l++;
            }
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        

        return maxlen;
    }
};
