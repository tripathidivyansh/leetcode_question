class Solution {
public:

    void solve(int index, vector<string>&ans, string& digit, string output, string mapping[]){
        if(index >= digit.size()){
            ans.push_back(output);
            return;
        }
        int number = digit[index]-'0';
        string value = mapping[number];
        for(int i = 0; i<value.size(); i++){
            output.push_back(value[i]);
            solve(index+1, ans, digit, output, mapping);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        string output;
        if(digits.size() == 0){
            return ans;
        }
        string mapping[10] ={"", "", "abc", "def", "ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
        solve(0,ans, digits, output,  mapping); 
        return ans;
    }
};