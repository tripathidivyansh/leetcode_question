// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         long long min = x;
//         for(int i = 1; i<n; i++){
//             min = (min+1)|x;
//         }
//         return min;
//     }
// };

class Solution {
public:
    long minEnd(int n, int x) {
        long result = x;
        long remaining = n - 1;
        long position = 1;
        
        while (remaining) {
            if (!(x & position)) {
                result |= (remaining & 1) * position;
                remaining >>= 1;
            }
            position <<= 1;
        }
        
        return result;
    }
};