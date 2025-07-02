class Solution {
public:
    bool solve(string s, string p) {
        if (p.empty()) {
            return s.empty();

        }
        bool first_char_matched = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
        if (p.length() >= 2 && p[1] == '*') {
            return solve(s, p.substr(2)) || (first_char_matched && solve(s.substr(1), p));
        } else {
            return first_char_matched && solve(s.substr(1), p.substr(1));
        }
    }
    bool isMatch(string s, string p) {
        return solve(s, p);

    }
};