class Solution {
public:
    bool solve(int index, string& s, unordered_set<string>& wordSet, vector<int>& dp) {
        if (index == s.size()) {
            return true;
        }

        if (dp[index] != -1) {
            return dp[index];
        }

        string temp;
        for (int i = index; i < s.size(); i++) {
            temp += s[i];
            if (wordSet.find(temp) != wordSet.end()) {
                if (solve(i + 1, s, wordSet, dp)) {
                    return dp[index] = true;
                }
            }
        }

        return dp[index] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<int> dp(s.size(), -1); 
        return solve(0, s, wordSet, dp);
    }
};
