class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int count = 1;
        int lastInterval = intervals[0][1];
        for(int i = 1; i<n; i++){
            if(intervals[i][0] >= lastInterval){
                count++;
                lastInterval = intervals[i][1];
            }
        }
        return n - count;
    }
};