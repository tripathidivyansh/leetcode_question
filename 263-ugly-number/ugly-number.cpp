class Solution {
public:
    bool isUgly(int n) {
        if(n<=0){
            return false;
        }
        for(int divisior:{2,3,5}){
            while(n%divisior == 0){
                n /= divisior;
            }
        }
        return n==1;
    }
};