class Solution {
public:
    string makeFancyString(string s) {
        string reSult = "";
        for(int i = 0; i<s.size(); i++){
            
            int len = reSult.length();
            if(len >=2 && reSult[len-1] == s[i] && reSult[len-2]== s[i]){
                continue;
            }
            reSult += s[i];
        }
        return reSult;
    }
};