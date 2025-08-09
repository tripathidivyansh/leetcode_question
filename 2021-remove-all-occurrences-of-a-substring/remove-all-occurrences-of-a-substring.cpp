class Solution {
public:
    string Solve(string s, string part){
        if(part.size() > s.size()) return s;
        
        while (s.find(part) != string::npos) {
            size_t pos = s.find(part);
            s.erase(pos, part.size());
        }
        
        return s; 
    }
    
    string removeOccurrences(string s, string part) {
        return Solve(s, part);
    }
};
