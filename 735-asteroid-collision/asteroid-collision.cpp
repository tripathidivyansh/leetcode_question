class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int>s;
        int n = a.size();
        for(int i = 0; i<n; i++){
            if(a[i] > 0){
                s.push(a[i]);
            }else{
                while(!s.empty() && s.top()> 0 && s.top() < abs(a[i])){
                    s.pop();
                }
                if(!s.empty() && s.top() == abs(a[i])){
                    s.pop();
                }else if(s.empty() || s.top() < 0){
                    s.push(a[i]);
                }
            }
        }
        vector<int> result;
        while(!s.empty()) {
            result.insert(result.begin(), s.top());
            s.pop();
        }
        return result;
    }
};


// class Solution {
// public:
//     vector<int> asteroidCollision(vector<int>& a) {
//         stack<int> s;
//         int n = a.size();
        
//         for(int i = 0; i < n; i++) {
//             if(a[i] > 0) {
//                 s.push(a[i]);
//             } else {
//                 while(!s.empty() && s.top() > 0 && s.top() < abs(a[i])) {
//                     s.pop();
//                 }
//                 if(!s.empty() && s.top() == abs(a[i])) {
//                     s.pop();
//                 } else if(s.empty() || s.top() < 0) {
//                     s.push(a[i]);
//                 }
//             }
//         }
        
//         vector<int> result;
//         while(!s.empty()) {
//             result.insert(result.begin(), s.top());
//             s.pop();
//         }
        
//         return result;
//     }
// };
