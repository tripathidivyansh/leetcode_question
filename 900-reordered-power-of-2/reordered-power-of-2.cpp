class Solution {
public:
    string getSorted(int n){
        string S = to_string(n);
        sort(S.begin(), S.end());

        return S;
    }
    bool reorderedPowerOf2(int n) {
        string S = getSorted(n);
        for(int p = 0; p<31; p++){
            if(S == getSorted(1 << p)){
                return true;
            }
        }
         return false;
    }
};
