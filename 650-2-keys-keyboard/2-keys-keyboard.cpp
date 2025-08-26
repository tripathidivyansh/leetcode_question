class Solution {
public:
    int minSteps(int n) {
       int ans = 0;
        for(int d = 2; d <= n; d++){

            while(n %d == 0){
                ans += d;
                n/= d;
            }
        }
        return ans;
    }
};








































