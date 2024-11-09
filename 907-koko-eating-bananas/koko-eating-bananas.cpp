// class Solution {
// public:

//     int findMax(vector<int>& piles){
//         int maxi = INT_MIN;
//         int n = piles.size();
//         for(int i = 0; i<n; i++){
//             maxi = max(maxi, piles[i]);
//         }
//         return maxi;
//     }

//     int calculateTotalHorus(vector<int>& piles, int hourly){
//         int totalH = 0;
//         int n = piles.size();
//         for(int i =0; i<n; i++){
//             // totalH += ceil((double)piles[i] / (double)hourly);
//             totalH += (piles[i] + hourly - 1) / hourly;
//         }
//         return totalH;
//     }
//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n = piles.size();
//         int low = 1, high = findMax(piles);
//         while(low<=high){
//             int mid = (low+high)/2;
//             int totalH =calculateTotalHorus(piles, mid);
//             if(totalH <= h){
//                 high = mid-1;
//             }else{
//                 low = mid+1;
//             }
//         }
//         return low;
//     }
// };


class Solution {
public:
    int findMax(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, piles[i]);
        }
        return maxi;
    }

    long long calculateTotalHorus(vector<int>& piles, int hourly) {
        long long totalH = 0;  // Use long long to prevent overflow
        int n = piles.size();
        for (int i = 0; i < n; i++) {
            totalH += (piles[i] + hourly - 1) / hourly;  // Ceil division without using floating-point operations
        }
        return totalH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = findMax(piles);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long totalH = calculateTotalHorus(piles, mid);  // totalH now uses long long

            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

