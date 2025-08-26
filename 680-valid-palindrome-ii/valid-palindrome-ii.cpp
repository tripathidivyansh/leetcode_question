class Solution {
public:
    bool checkPalindrome(const string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            } else {
                return checkPalindrome(s, i+1, j) || checkPalindrome(s, i, j-1);
            }
        }
        return true;
    }
};






























