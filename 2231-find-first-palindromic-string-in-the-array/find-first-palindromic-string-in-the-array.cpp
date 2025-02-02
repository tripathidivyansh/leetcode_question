class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        

        string  result = "";
        for(int i = 0; i<n; i++){
            int left = 0, high = words[i].size()-1;
            while(left<=high){
                if(words[i][left] != words[i][high]){
                    break;
                }
                left++;
                high--;
            }
            if(left>= high){
            result = words[i];
            return result;
            }   
        }
        return result;
    }
};