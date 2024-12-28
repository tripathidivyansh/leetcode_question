class Solution {
public:
    bool isPowerOfThree(int n) {
        int ans = 1;
        for(int i = 0; i<31; i++){
            if(ans == n) return true;
            if(ans > INT_MAX /3) break;
            ans *= 3;
        }
        return false;
    }
};