class Solution {
public:
    bool iSvowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
               c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
    string sortVowels(string s) {
        vector<char> v;
        for(char c : s){
            if(iSvowel(c)){
                v.push_back(c);
            }
        }
        sort(v.begin(), v.end());
        int index = 0;
        for(char &c : s){
            if(iSvowel(c)){
                c = v[index++];
            }
        }
        return s;
    }
};































