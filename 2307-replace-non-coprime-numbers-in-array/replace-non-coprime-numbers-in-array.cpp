class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>reSult;
        for(int num : nums){

            while(!reSult.empty()){
                int prev = reSult.back();
                int curr = num;
                int GCD = gcd(prev, curr);

                if(GCD == 1) break;
                reSult.pop_back();
                int lcm = prev / GCD * curr;
                num = lcm;
            }
            reSult.push_back(num);
        }
        return reSult;
    }
};
