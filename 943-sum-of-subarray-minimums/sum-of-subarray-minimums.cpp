// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         int sum = 0;
//         int mod = 1e9 + 7;
//         for(int i = 0; i<n; i++){
//             int mini = arr[i];
//             for(int j = i; j<n; j++){
//                 mini = min(mini, arr[j]);
//                 sum = (sum + mini) % mod;
//             }
//         }
//         return sum;
//     }
// };












class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        
        for(int i = 0; i < n; i++) {
            int L = 0, R = 0;
            for(int j = i - 1; j >= 0; j--) {
                if(arr[j] > arr[i]) L++;
                else break;
            }
            for(int j = i + 1; j < n; j++) {
                if(arr[j] >= arr[i]) R++;
                else break;
            }
            sum = (sum + (long long)arr[i] * (L + 1) * (R + 1)) % mod;
        }
        return sum;
    }
};
