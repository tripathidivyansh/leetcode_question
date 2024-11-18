class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int count = 0;
        sort(citations.begin(), citations.end());
        for(int i = n-1; i>= 0; i--){
            if (citations[i] >= count + 1) {
                count++;
           }else{
            break;
           }
        }
        return count++;
    }
};