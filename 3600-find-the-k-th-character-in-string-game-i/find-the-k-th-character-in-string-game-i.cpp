class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.length() < k){

            string nextpart = "";
            for(char c : word){
                if(c == 'z'){
                    nextpart += 'a';
                }else{
                    nextpart += c+1;
                }
            }
            word += nextpart;
        }
        

        return word[k-1];
    }
};