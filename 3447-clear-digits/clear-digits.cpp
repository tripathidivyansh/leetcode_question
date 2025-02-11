class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for(auto c : s){
            if(c >= '0' && c <='9')
                ans.pop_back();
            else
                ans.push_back(c);
        }
        return ans;
    }
};