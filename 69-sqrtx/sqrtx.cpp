class Solution {
public:
    int mySqrt(int x) {
        if(x <=1) return x;
        long long ans = 0;
        for(int i = 1; i<=x; i++){
            long long ans1 = 1LL * i * i;
            if(ans1 <= x){
                ans = i;
            }else{
                break;
            }
        }
        return ans;
    }
};