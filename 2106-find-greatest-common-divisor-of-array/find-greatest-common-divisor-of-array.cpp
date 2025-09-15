// class Solution {
// public:
//     int findGCD(vector<int>& nums) {
//         int miniE = *min_element(nums.begin(), nums.end());
//         int maxE = *max_element(nums.begin(), nums.end());
//         return __gcd(miniE, maxE);
//     }
// };
class Solution {
public:

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int findGCD(vector<int>& nums) {
        int miniE = *min_element(nums.begin(), nums.end());

        int maxE = *max_element(nums.begin(), nums.end());
        return gcd(miniE, maxE);
    }
};



































































































































































































