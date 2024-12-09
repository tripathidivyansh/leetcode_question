// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         if(num < 0){
//             return false;
//         }
//         for(long long i = 1; i<=num; i++){
//             if(i*i==num){
//                 return true;
//             }
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
        int low = 0, high = num;
        while (low <= high){
            long long mid = (high+low)/2;
            long long squre = mid*mid;

            if(squre == num){
                return true;
            }else if(squre < num){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return false;
    }
};