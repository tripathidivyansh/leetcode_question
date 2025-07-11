class Solution {
public:
    void solve(int index, string&digits, vector<string>&result, string path, string mapping[]){
        if(index >= digits.size()){
            result.push_back(path);
            return;
        }
        int number = digits[index] -'0';
        string value = mapping[number];
        for(int i = 0; i<value.size(); i++){
            path.push_back(value[i]);
            solve(index+1, digits, result, path, mapping);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string>result;

        string path;
        if(n == 0){
            return result;
        }
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl","mno", "pqrs", "tuv", "wxyz"};
        solve(0, digits, result, path, mapping);
        return result;
    }
};