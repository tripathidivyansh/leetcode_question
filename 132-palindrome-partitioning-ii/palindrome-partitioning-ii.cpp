class Solution {
public:

    bool isPalindrome(int i, int j, const string& s) {
        while(i < j) {

            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int index, string &s, vector<int>& dp) {
        if(index == s.size()) return 0; 
        if(dp[index] != -1) return dp[index];
        int minCuts = INT_MAX;
        
        for(int i = index; i < s.size(); i++) {
            if(isPalindrome(index, i, s)) {
                int cuts = 1 + solve(i + 1, s, dp);
                minCuts = min(minCuts, cuts);
            }
        }

        dp[index] = minCuts;
        return dp[index];
    }

    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return solve(0, s, dp) - 1;
    }
};
