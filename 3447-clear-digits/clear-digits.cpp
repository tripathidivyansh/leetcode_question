// class Solution {
// public:
//     string clearDigits(string s) {
//         string ans;
//         for(auto c : s){
//             if(c >= '0' && c <='9')
//                 ans.pop_back();
//             else
//                 ans.push_back(c);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    string clearDigits(string s) {
        stack<char>ans;
        for(auto c : s){
            if(c>= '0' && c<='9'){
                if(!ans.empty())
                     ans.pop();
            }else{
                ans.push(c);
            }
        }
        string ans1;
        while(!ans.empty()){
            ans1+= ans.top();
            ans.pop();
        }
        // return ans1;
        reverse(ans1.begin(), ans1.end());
        return ans1;
    }
};