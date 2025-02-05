class Solution {
private: 
    double mypow1(double x, int n){
        if(n==0){
            return 1;
        }
        if(x==1){
            return 1;
        }
        double half = mypow1(x, n/2);
        if(n%2 == 0){
            return half*half;
        }else if(n>0){
            return  x * half * half;
        }else{
            return (half * half) / x;
        }
    }
public:
    double myPow(double x, int n) {
        return mypow1(x,n);
    }
};