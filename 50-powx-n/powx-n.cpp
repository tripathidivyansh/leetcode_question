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
        }else{
            return (n > 0) ? x * half * half : (half * half) / x;
        }
    }
public:
    double myPow(double x, int n) {
        // double ans = pow(x, n);
        // return ans;
        // return pow(x,n);

        return mypow1(x,n);
    }
};