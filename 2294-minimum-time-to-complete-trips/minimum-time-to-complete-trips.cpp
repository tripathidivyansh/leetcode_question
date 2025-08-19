class Solution {
public:
    bool isPossible(vector<int>& time, long long givenTime, int totalTrips) {
        long long actualTrips = 0;
        for (int &t : time) {
            actualTrips += givenTime / t;
            if (actualTrips >= totalTrips) return true; 
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1;  
        long long r = (long long)*min_element(time.begin(), time.end()) * totalTrips; 

        while (l < r) {
            long long mid = l + (r - l) / 2;
            if (isPossible(time, mid, totalTrips)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};







