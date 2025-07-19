class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> st(begin(folder), end(folder));
        vector<string> result;

        for (string currFolder : folder) {
            bool isSubfolder = false;
            string temp = currFolder;

            while (!temp.empty()) {
                size_t position_last_variable = temp.find_last_of('/');
                if (position_last_variable == 0) break;  
                temp = temp.substr(0, position_last_variable);
                if (st.find(temp) != st.end()) {
                    isSubfolder = true;
                    break;
                }
            }

            if (!isSubfolder) {
                result.push_back(currFolder);
            }
        }
        return result;
        
    }
};
