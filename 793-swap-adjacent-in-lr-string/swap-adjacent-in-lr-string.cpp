class Solution {
public:
    bool canTransform(string start, string result) {
        int n = start.size();
        int i = 0, j = 0;
        
        while (i < n || j < n) {
            while (i < n && start[i] == 'X') i++;
            while (j < n && result[j] == 'X') j++;
            if (i == n && j == n) return true;
            if (i == n || j == n) return false;
            if (start[i] != result[j]) return false;
            if (start[i] == 'L' && i < j) return false; 
            if (start[i] == 'R' && i > j) return false; 
            i++;
            j++;
        }
        return true;
    }
};


























































































