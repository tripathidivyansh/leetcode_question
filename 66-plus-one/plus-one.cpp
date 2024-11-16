class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n = arr.size();
        int carry = 1;
        for(int i = n-1; i>=0; i--){
            arr[i] += carry;
            if(arr[i] == 10){
                arr[i] = 0;
                carry = 1;
            }else{
                carry = 0;
                break;
            }
        }
        if(carry == 1){
            arr.insert(arr.begin(), 1);
        }
        return arr;
    }
};

