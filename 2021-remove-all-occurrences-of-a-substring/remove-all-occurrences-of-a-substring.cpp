class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(true){
            int index = s.find(part);

            if(index == string::npos){
                break;
            }
            s.erase(index, part.length());
        }
        return s;

    }
};



