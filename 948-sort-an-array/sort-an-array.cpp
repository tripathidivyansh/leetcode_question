class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto x : nums){
            pq.push(x);
        }
        vector<int>ans;
        for(int i = 0; i<n; i++){
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};