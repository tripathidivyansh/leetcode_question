class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>vec(2001, 0);
        for(int &x : arr){

            vec[x + 1000]++;
        }
        sort(vec.begin(), vec.end());
        for(int i = 1; i<2001; i++){
            if(vec[i] != 0 && vec[i] == vec[i-1]){
                return false;
            }
        }
        return true;
    }

};