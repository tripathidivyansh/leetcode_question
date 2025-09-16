class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;



        for (int num : nums) {
            st.push_back(num);            
            while (st.size() > 1) {

                int a = st.back(); 
                int b = st[st.size() - 2];
                int g = gcd(a, b);

                if (g == 1) break;

                st.pop_back();
                st.pop_back();
                long long lcm = (1LL * a / g) * b; 
                st.push_back((int)lcm);

            }
        }
        return st;
    }
};



















































































