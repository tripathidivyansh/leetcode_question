#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        int result = 10; 
        int uniqueDigits = 9, available = 9;

        for (int i = 2; i <= n && available > 0; i++) {
            uniqueDigits *= available;
            result += uniqueDigits;
            available--; 
        }
        return result;
    }
};
