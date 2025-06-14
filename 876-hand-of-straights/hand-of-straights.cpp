class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> freq;

        for (int num : hand) {
            freq[num]++;
            pq.push(num);
        }
        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();
            if (freq[first] == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                int card = first + i;
                if (freq[card] == 0) {
                    return false;
                }
                freq[card]--;
            }
        }

        return true;
    }
};
