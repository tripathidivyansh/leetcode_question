class Solution {
public:
    vector<int>getVectorcount(int n){
        vector<int>vec(10, 0);
        while(n){
            vec[n%10]++;
            n/= 10;
        }
        return vec;
    }
    bool reorderedPowerOf2(int n) {
        vector<int>input = getVectorcount(n);
        for(int p = 0; p<31; p++){
            if(input == getVectorcount(1 << p)){
                return true;
            }
        }       
        return false;
    }
    // unordered_set<string>St;
    // void buildSet(){
    //     for(int p = 0; p<31; p++){

    //         string S = to_string(1 << p);
    //         sort(S.begin(), S.end());
    //         St.insert(S);
    //     }
    // }
    // bool reorderedPowerOf2(int n) {
    //     if(St.empty()){
    //         buildSet();
    //     }
    //     string S = to_string(n);
    //     sort(S.begin(), S.end());
    //     return St.count(S);
    // }
};
// class Solution {
// public:
//     string getSorted(int n){
//         string S = to_string(n);
//         sort(S.begin(), S.end());

//         return S;
//     }
//     bool reorderedPowerOf2(int n) {
//         string S = getSorted(n);
//         for(int p = 0; p<31; p++){
//             if(S == getSorted(1 << p)){
//                 return true;
//             }
//         }
//          return false;
//     }
// };