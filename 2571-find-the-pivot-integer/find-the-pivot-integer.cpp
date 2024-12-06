class Solution {
public:
    int pivotInteger(int n) {
        int sum = 0;
        for(int i = 0; i<=n; i++){
            sum += i;
        }
        int leftSum = 0;
        for(int i = 0; i<=n; i++){
            if(leftSum == sum-leftSum-i){
                return i;
            }
            leftSum += i;
        }
        return -1;
    }
};