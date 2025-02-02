class Solution {
public:
    bool checkString(string s) {
        bool found = false;
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'b'){
                found = true;
            }else if(s[i] == 'a' && found){
                return false;
            }
        }
        return true;
    }
};