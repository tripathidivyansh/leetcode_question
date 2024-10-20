// class Solution {
// public:
//     bool isPalindromeHelper(int l, int r, string s){

//         if(l>= r) return true;
//         if(!isalnum(s[l]))return isPalindromeHelper(l+1,r,s);
//         if(!isalnum(s[r]))return isPalindromeHelper(l,r-1,s);
//         if(tolower(s[l]) != tolower(s[r])) return false;
//         return isPalindromeHelper(l+1, r-1, s);
//     }
//     bool isPalindrome(string s) {
//         return isPalindromeHelper(0, s.size()-1, s);
//     }
// };

class Solution{
public:
    bool isPalindrome(string s){
        int left = 0;
        int right = s.size()-1;

        while(left< right){
            if(!isalnum(s[left])){
                left++;
            }else if(!isalnum(s[right])){
                right--;
            }else if(tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};