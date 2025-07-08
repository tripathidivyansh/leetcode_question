class Solution {
public:
    int binarySearch(vector<vector<int>>& jobs, int target) {
        int low = 0, high = jobs.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (jobs[mid][0] >= target) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

    int solve(int index, vector<vector<int>>& jobs, vector<int>& dp) {
        if (index >= jobs.size()) return 0;
        if (dp[index] != -1) return dp[index];

        
        int skip = solve(index + 1, jobs, dp);

        int nextIndex = binarySearch(jobs, jobs[index][1]);  
        int take = jobs[index][2] + solve(nextIndex, jobs, dp);

        return dp[index] = max(skip, take);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }
        sort(jobs.begin(), jobs.end()); 
        vector<int> dp(n, -1);
        return solve(0, jobs, dp);
    }
};