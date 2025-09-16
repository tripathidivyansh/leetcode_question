class Solution {
public:
    static bool compare(const string &a, const string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int num : nums){
            arr.push_back(to_string(num));
        }
        sort(arr.begin(), arr.end(), compare);
        if(arr[0] == "0") return "0";

        string reSult;
        for(const string &s : arr){
            reSult += s;
        }
        return reSult;
    }
};
