class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        stack<char>s1;
        for(int i = 0; i<n; i++){
            s1.push(s[i]);
        }
        for(int i = 0; i<n; i++){
            s[i] = s1.top();
            s1.pop();
        }
        
    }
};

// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//        int left = 0, right = s.size()-1;
//        while(left < right){
//         swap(s[left], s[right]);
//         left++;
//         right--;
//        }
//     }
// };