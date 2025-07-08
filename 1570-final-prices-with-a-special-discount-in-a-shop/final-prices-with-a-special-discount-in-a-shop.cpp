class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        vector<int>ans = prices;

        for(int i = 0; i<prices.size(); i++){
            while(!st.empty() && prices[st.top()] >= prices[i]){
                int index = st.top();
                st.pop();
                ans[index] = prices[index] - prices[i];
            }
            st.push(i);
        }
        return ans;
    }
};