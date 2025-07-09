class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int> freearray;
        freearray.push_back(startTime[0]);  

        for (int i = 1; i < startTime.size(); i++) {  
            freearray.push_back(startTime[i] - endTime[i - 1]);
        }

        freearray.push_back(eventTime - endTime.back()); 
        int n = freearray.size();
        int i = 0, j = 0, maxSum = 0, currSum = 0;
        while (j < n) {
            currSum += freearray[j];
            if (j - i + 1 > k + 1) {

                currSum -= freearray[i];
                i++;
            }

            maxSum = max(maxSum, currSum);
            j++;
        }

        return maxSum;
    }
    
};
