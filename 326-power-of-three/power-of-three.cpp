class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n%3 != 0){
            return false;
        }
        return isPowerOfThree(n/3);
    }
};