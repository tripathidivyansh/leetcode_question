class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int>pq(amount.begin(), amount.end());
        int count = 0;

        while(pq.top() != 0){
            count++;
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            a--;
            b--;
            pq.push(a);
            pq.push(b);
        }
        return count;
    }
};