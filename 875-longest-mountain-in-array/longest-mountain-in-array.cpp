class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int maxLen = 0;

        for (int i = 1; i < n - 1; ) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {
                int count = 1;
                int j = i;
                while (j > 0 && arr[j] > arr[j - 1]) {

                    j--;
                    count++;
                }
                while (i < n - 1 && arr[i] > arr[i + 1]) {
                    
                    i++;
                    count++;
                }
                maxLen = max(maxLen, count);
            } else {
                i++;
            }
        }

        return maxLen;
    }
};