class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>reSult;
        for(int i = 1; i<=n/2; i++){

            reSult.push_back(i);
            reSult.push_back(-i);
        }
        if(n%2 == 1){
            
            reSult.push_back(0);
        }
        return reSult;
    }
};





