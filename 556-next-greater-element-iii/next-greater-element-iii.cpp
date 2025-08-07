class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int original = n;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        reverse(digits.begin(), digits.end()); 
        int size = digits.size();
        int ind = -1;
        for (int i = size - 2; i >= 0; i--) {
            if (digits[i] < digits[i + 1]) {
                ind = i;
                break;
            }
        }
        if (ind == -1) return -1;
        for (int i = size - 1; i > ind; i--) {
            if (digits[i] > digits[ind]) {
                swap(digits[i], digits[ind]);
                break;
            }
        }
        reverse(digits.begin() + ind + 1, digits.end());
        long long result = 0;
        for (int d : digits) {
            result = result * 10 + d;
        }
        if (result <= INT_MAX) {
            return (int)result;
        } else {
            return -1;
        }

    }
};
