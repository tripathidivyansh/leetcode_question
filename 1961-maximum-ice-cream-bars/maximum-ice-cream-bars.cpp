class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int Sum = 0, maxSum = 0, count = 0;

        int l = 0, r = 0;
        while(r < costs.size()){
            Sum += costs[r];
            count++;
            if(Sum > coins){
                break;
            }
            // count++;
            r++;
            maxSum = max(maxSum, count);
        }
        return maxSum;
    }
};