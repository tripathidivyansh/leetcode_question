// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         if(num==0){
//             return 0;
//         }
//         if(num==1){
//             return 1;
//         }
//         int result = 0;
//         int low = 0, high = num;
//         while(low < high){
//             int mid = (low+high)/2;
//             // if(num*num % num ==0){
//             //     return true;
//             // }
//             result = num*num;


//         }
//         return false;
//     }
// };

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num < 0){
            return false;
        }
        for(long long i = 1; i<=num; i++){
            if(i*i==num){
                return true;
            }
        }
        return false;
    }
};