class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string ans = "";
        while(n > 0){
            int digit = n % 10;
            ans += char('0' + digit); 
            n /= 10;
        }

        sort(ans.begin(), ans.end()); 
        for(int i = 0; i < 31; i++) { 
            int pow2 = 1 << i;
            string s = to_string(pow2);
            sort(s.begin(), s.end());
            if(s == ans) return true;
        }
        return false;
    }
};

