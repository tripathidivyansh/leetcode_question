class Solution {
public:
    int hammingWeight(int n) {
        string binary = "";    
        int temp = n;         

        if(temp == 0) binary = "0";
        while(temp > 0){
            binary = to_string(temp % 2) + binary;
            temp /= 2;
        }

        int count = 0;
        for(char c : binary){
            if(c == '1'){
                count++;
            }
        }

        return count;
    }
};
