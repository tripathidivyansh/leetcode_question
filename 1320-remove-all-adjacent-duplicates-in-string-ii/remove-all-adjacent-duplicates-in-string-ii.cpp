class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (auto ch : s) {

            if (st.empty() || st.top().first != ch) {
                st.push({ch, 1});
            } else {
                auto top = st.top();
                st.pop();
                st.push({ch, top.second + 1});
            }

            if (st.top().second == k) {
                st.pop();
            }
        }
        string result = "";
        while (!st.empty()) {
            auto top = st.top();  
            st.pop();
            result.append(top.second, top.first);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
