class Solution {
public:
    bool check(stack<char>&St, string& part, int n){
        stack<char>temp = St;
        for(int index = n-1; index >= 0; index--){

            if(temp.top() != part[index]){
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        // while(true){
        //     int index = s.find(part);

        //     if(index == string::npos){
        //         break;
        //     }
        //     s.erase(index, part.length());
        // }
        // return s;
        stack<char>St;
        int m = s.size();
        int n = part.size();
        for(int i = 0; i<m; i++){

            St.push(s[i]);
            if(St.size() >= n && check(St, part, n) == true){
                for(int j = 0; j<n; j++){
                    St.pop();
                }
            }
        }
        string reSult = "";
        while(!St.empty()){
            reSult.push_back(St.top());
            St.pop();
        }
        reverse(reSult.begin(), reSult.end());
        return reSult;
    }
};









