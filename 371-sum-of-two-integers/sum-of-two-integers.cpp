class Solution {
public:
    int getSum(int a, int b) {
        // return (a+b);
        while(b!= 0){
            int carray = (a&b) << 1;
            a = a^b;
            b = carray;
        }
        return a;
    }
};