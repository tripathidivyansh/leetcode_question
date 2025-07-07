class Solution {
public:
    string removeDuplicates(string s) {
        string temp;
        int i = 0;

        temp.push_back(s[0]);
        for(int i = 1; i<s.size(); i++){
            if(!temp.empty() && s[i] == temp.back()){
                temp.pop_back();
            }else{
                temp.push_back(s[i]);
            }
        }
        return temp;
    }
};