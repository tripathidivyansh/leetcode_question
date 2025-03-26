class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(int index, vector<string> &ds, string &s, vector<vector<string>> &result) {
        if (index >= s.size()) {
            result.push_back(ds);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                ds.push_back(s.substr(index, i - index + 1));
                solve(i + 1, ds, s, result);
                ds.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> result;
        solve(0, ds, s, result);
        return result;
    }
};
