class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0, maxsum = 0;
        for(int i = 0; i<k; i++){
            sum += cardPoints[i];
        }
        maxsum = sum;
        for(int i = 1; i<=k; i++){
            sum -= cardPoints[k-i];
            sum += cardPoints[n-i];
            maxsum = max(maxsum, sum);
        }
        return maxsum;
    }
};