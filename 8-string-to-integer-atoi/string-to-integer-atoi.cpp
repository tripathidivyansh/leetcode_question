#include <bits/stdc++.h>
class Solution {
public:
    int solve(int i, string &s, long ans, int sign) {
        if (i >= s.size() || !isdigit(s[i])) {
            return sign * ans;
        }
        ans = ans * 10 + (s[i] - '0');
        if (sign == 1 && ans > INT_MAX) return INT_MAX;
        if (sign == -1 && -ans < INT_MIN) return INT_MIN;

        return solve(i + 1, s, ans, sign);
    }

    int myAtoi(string s) {
        if (s.empty()) return 0;

        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        if (i == s.size()) return 0;

        int sign = 1;
        
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }
        return solve(i, s, 0, sign);
    }
};
