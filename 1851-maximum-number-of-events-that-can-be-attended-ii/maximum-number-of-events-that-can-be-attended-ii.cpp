class Solution {
public:
    int solve(int index, vector<vector<int>>& events, int k, vector<vector<int>>& dp) {
        if (index >= events.size() || k == 0) return 0;
        if (dp[index][k] != -1) return dp[index][k];

        int skip = solve(index + 1, events, k, dp);

        int next = binarySearch(events, events[index][1]);
        int take = events[index][2] + solve(next, events, k - 1, dp);

        return dp[index][k] = max(skip, take);
    }
    int binarySearch(const vector<vector<int>>& events, int targetEnd) {
        int low = 0, high = events.size();
        while (low < high) {
            
            int mid = (low + high) / 2;
            if (events[mid][0] > targetEnd)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end()); 
        int n = events.size();
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        return solve(0, events, k, dp);
    }
};
