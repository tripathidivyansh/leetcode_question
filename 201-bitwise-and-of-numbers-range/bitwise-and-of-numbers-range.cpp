class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int Shift = 0;
        while(left < right){

            left >>= 1;
            right >>= 1;
            Shift++;
        }
        return left << Shift;
    }
};