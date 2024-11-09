class Solution {
public:
    long long minEnd(int n, int x) {
        long long min = x;
        for(int i = 1; i<n; i++){
            min = (min+1)|x;
        }
        return min;
    }
};