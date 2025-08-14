class Solution {
public:
    int lengthOfLastWord(string s) {
        // string ans = "";
        // for(int i = s.size() -1; i>= 0; i--){
            
        //     if(s[i] != ' '){
        //         ans += s[i];
        //     }else if(ans.size() > 0){
        //         break;
        //     }
        // }
        
        // return ans.size();
        int lenght = 0;
        for(int i = s.size()-1; i>= 0; i--){

            if(s[i] != ' '){
                lenght++;
            }else if(lenght > 0){
                break;
            }
        }
        return lenght;
    }
};


