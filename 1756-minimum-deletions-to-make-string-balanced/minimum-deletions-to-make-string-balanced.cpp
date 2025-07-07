class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int count = 0;

        for(char i : s){
            if(i == 'b') st.push('b');
            else if(!st.empty() && st.top() == 'b' && i == 'a'){
                st.pop();
                count++;
            }
        }
        return count;
    }
};