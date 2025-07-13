class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;
        return gcd(b, a % b);
    }
    bool canMeasureWater(int x, int y, int target) {
        if(x + y < target) return false;
        if(x == 0|| y == 0){

            return target == 0 || target == x + y;
        }
        return target % gcd (x, y) == 0;
    }
};