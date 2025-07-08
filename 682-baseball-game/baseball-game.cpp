class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        int ans = 0;

        for(string& S : operations){
            if(S == "+"){
                int ans1 = s.top();
                s.pop();
                int ans2 = s.top();
                ans = ans1 + ans2;
                s.push(ans1);
                s.push(ans);
            }else if(S == "D"){
                s.push(s.top()*2);
            }else if(S == "C"){
                s.pop();
            }else s.push(stoi(S));
        }
        int ans3 = 0;
        while(!s.empty()){
            ans3 += s.top();
            s.pop();
        }

        return ans3;
    }
};