class Solution {
public:
    int canMakeBokkay(vector<int>& bloomDay, int mid, int k) {
        int bouqkcount = 0;
        int consective_count = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                consective_count++;
            } else {
                consective_count = 0;
            }
            if (consective_count == k) {
                bouqkcount++;
                consective_count = 0;
            }

        }
        return bouqkcount;  
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int startDay = 1; 
        int endDay = *max_element(bloomDay.begin(), bloomDay.end());
        int minDay = -1;
        while (startDay <= endDay) {
            int mid = startDay + (endDay - startDay) / 2;  

            if (canMakeBokkay(bloomDay, mid, k) >= m) {
                minDay = mid;
                endDay = mid - 1;  
            } else {
                startDay = mid + 1;  
            }
        }

        return minDay; 
    }
};