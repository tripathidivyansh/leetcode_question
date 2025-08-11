class Solution {
public:
    int m = 1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>powerS;

        vector<int>reSult;
        for(int i = 0; i<32; i++){
            if((n &(1 << i)) != 0){
                powerS.push_back(1 << i);
            }
        }
        for(auto &query : queries){
            int Start = query[0];
            int end = query[1];
            long long product = 1;
            
            for(int i = Start;  i<= end; i++){
                product = (product *powerS[i]) % m;
            }
            reSult.push_back(product);
        }
        return reSult;
    }
};


