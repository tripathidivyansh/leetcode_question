class Solution {
public:
    // void Solve(int index, string &s1, string &s2, bool &found) {
    //     if (found) return; 

    //     if (index == s1.size()) {
    //         if (s2.find(s1) != string::npos) {
    //             found = true;
    //         }
    //         return;
    //     }

    //     for (int i = index; i < s1.size(); i++) {
    //         swap(s1[i], s1[index]);
    //         Solve(index + 1, s1, s2, found);
    //         swap(s1[i], s1[index]); 
    //     }
    // }

    // bool checkInclusion(string s1, string s2) {
    //     bool found = false;
    //     Solve(0, s1, s2, found);
    //     return found;
    // }
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n > m) return false;
        sort(s1.begin(), s1.end());
        for(int i = 0; i<=m-n; i++){
            string substr = s2.substr(i, n);
            sort(substr.begin(), substr.end());
            if(s1 == substr)return true;
        }
        return false;
    }
};