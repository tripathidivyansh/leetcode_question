// class Solution {
// public:
//     int findNumbers(vector<int>& nums) {
//         int count = 0;
//         for (int num : nums) {
//             if (to_string(num).size() % 2 == 0) {
//                 count++;
//             }
//         }
//         return count;

//     }
// };










class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        
        for (int num : nums) {
            int digits = 0;
            int x = num;
            
            while (x > 0) {
                x /= 10;
                digits++;
            }
            
            if (digits % 2 == 0) {
                count++;
            }
        }
        return count;
    }

};









