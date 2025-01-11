class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        string start1 = event1[0];
        string end1 = event1[1];

        string start2 = event2[0];
        string end2 = event2[1];

        if(start1 <= end2 &&  end1 >= start2){
            return true;
        }
        return false;
    }
};