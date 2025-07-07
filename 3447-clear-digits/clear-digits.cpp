class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();
        stack<char>ans;

        for(auto c : s){
            if(c >= '0' && c<= '9'){
                if(!ans.empty()){
                    ans.pop();
                }
            }else{
                ans.push(c);
            }
        }
        string ans1;

        while(!ans.empty()){
            ans1 += ans.top();
            ans.pop();
        }
        reverse(ans1.begin(), ans1.end());
        return ans1;
    }
};