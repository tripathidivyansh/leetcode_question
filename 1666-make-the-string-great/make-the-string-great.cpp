class Solution {
public:
    string makeGood(string s) {
        int n = s.size();
        string result;

        for(auto & c : s){
            if(result.size() > 0 && abs(c - result.back()) == 32){
                result.pop_back();
            }else{
                result.push_back(c);
            }
        }
        return result;
    }
};