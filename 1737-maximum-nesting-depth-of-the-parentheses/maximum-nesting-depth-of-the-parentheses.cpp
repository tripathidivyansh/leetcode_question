class Solution {
public:
    int maxDepth(string s) {
        int count = 0, maxcount = 0;
        for(char S : s){

            if(S == '('){
                count++;
                maxcount = max(maxcount, count);
            }else if(S == ')'){
                count--;
            }
        }
        return maxcount;
    }
};