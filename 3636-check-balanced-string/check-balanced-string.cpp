class Solution {
public:
    bool isBalanced(string num) {
        int n = num.size();
        int oddSum = 0;
        int evenSum = 0;
        for(int i  = 0; i<n; i++){
            int digit = num[i]-'0';
            if(i % 2 == 0){
                evenSum+=digit;
            }else{
                oddSum+=digit;
            }
        }
        return (oddSum==evenSum);
    }
};