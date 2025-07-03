class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxLen = 0;
        for (int uniqueTarget = 1; uniqueTarget <= 26; uniqueTarget++) {

            unordered_map<char, int> freq;
            int l = 0, r = 0;
            int unique = 0, countAtLeastK = 0;

            while (r < s.size()) {
                if (freq[s[r]] == 0) unique++;
                freq[s[r]]++;
                if (freq[s[r]] == k) countAtLeastK++;
                while (unique > uniqueTarget) {
                    if (freq[s[l]] == k) countAtLeastK--;
                    
                    freq[s[l]]--;
                    if (freq[s[l]] == 0) unique--;
                    l++;
                }
                if (unique == countAtLeastK)
                    maxLen = max(maxLen, r - l + 1);

                r++;
            }
        }

        return maxLen;
    }
};
