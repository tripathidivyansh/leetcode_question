class Solution {
public:
    void solve(int index, int &count, int &result, vector<int>& resultant, vector<vector<int>>& requests) {
        if(index >= requests.size()) {
            bool isValid = true;

            for(int val : resultant) {
                if(val != 0) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                result = max(result, count);
            }
            return;
        }
        int from = requests[index][0];
        int to = requests[index][1];

        resultant[from]--;
        resultant[to]++;
        count++;
        solve(index + 1, count, result, resultant, requests);
        
        resultant[from]++;
        resultant[to]--;
        count--;

        solve(index + 1, count, result, resultant, requests);
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> resultant(n, 0);
        int result = INT_MIN;
        int count = 0;
        solve(0, count, result, resultant, requests);
        return result;
    }
};
