class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int ans3 = 0;

        for (string& c : tokens) {
            if (c == "+" || c == "-" || c == "*" || c == "/") {
                int ans = stoi(s.top());
                s.pop();
                int ans1 = stoi(s.top());
                s.pop();

                if (c == "+") {
                    ans3 = ans1 + ans;
                } else if (c == "-") {
                    ans3 = ans1 - ans;
                } else if (c == "*") {
                    ans3 = ans1 * ans;
                } else if (c == "/") {
                    ans3 = ans1 / ans;
                }
                s.push(to_string(ans3));
            } else {
                s.push(c);
            }
        }
        return stoi(s.top());
    }
};
