class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();

        if(n!=m){
            return false;
        }
        string concatenated = s + s;
        // this line for the handdle to campre the substring is present is not in the string
        return concatenated.find(goal) != string::npos;

    }
};