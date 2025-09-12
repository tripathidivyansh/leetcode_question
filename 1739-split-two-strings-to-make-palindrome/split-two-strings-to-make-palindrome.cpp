class Solution {
public:
    bool iSpalindrome(string &s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool check(string &x, string &y) {
        int i = 0, j = x.size() - 1;
        while(i < j && x[i] == y[j]) {
            i++;
            j--;
        }
        if(i >= j) return true; 
        return iSpalindrome(x, i, j) || iSpalindrome(y, i, j);
    }

    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};





















































































