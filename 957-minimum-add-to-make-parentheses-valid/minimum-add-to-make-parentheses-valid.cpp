class Solution {
public:
    int minAddToMakeValid(string s) {
        // int open= 0;
        // int close = 0;

        // for(char c : s){
        //     if(c == '('){
        //         open++;
        //     }else if(c == ')'){
        //         if(open > 0){
        //             open--;
        //         }else{
        //             close++;
        //         }
        //     }
        // }

        // return open + close;
        stack<char>st;
        for(char c : s){
            if(c == '('){
                st.push(c);
            }else if(c == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    st.push(')');
                }
            }
        }
        return st.size();
    }
};