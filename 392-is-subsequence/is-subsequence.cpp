class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int j = t.size();
        int count = 0;
        for (int i = 0; i < j && count < n; i++) { 
            if (s[count] == t[i]) {  
                count++;
            }
        }
        if(count == n){
            return true;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int sindex = 0;
//         int tindex = 0;

//         while(sindex < s.size() && tindex < t.size()){
//             if(s[sindex]== t[tindex]){
//                 sindex++;
//             }
//             tindex++;
//         }
//         return sindex == s.size();
//     }
// };