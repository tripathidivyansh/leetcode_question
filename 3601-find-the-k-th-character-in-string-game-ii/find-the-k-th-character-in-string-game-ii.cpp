class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {

        if (k == 1) return 'a';

        long long len = 1;
        long long newk = -1;
        int operationtype = -1;

        int n = operations.size();
        for (int i = 0; i < n; i++) {
            len *= 2;
            if (len >= k) {
                operationtype = operations[i];
                newk = k - len / 2;
                break;
            }
        }
        char ch = kthCharacter(newk, operations);
        if (operationtype == 0) {
            return ch;
        } else {
            if (ch == 'z') {
                return 'a';
            } else {
                return ch + 1;
            }
        }
    }
};
