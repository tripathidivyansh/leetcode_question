// class Solution {
// public:
//     int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
//         sort(arr1.begin(), arr1.end());
//         sort(arr2.begin(), arr2.end());
//         int count = 0;
//         int i = 0, j = 0;
//         while(i < arr1.size() && j < arr2.size()){
//             if(abs(arr1[i] - arr2[j]) <= d){
//                 count++;
//                 i++;

//             }else if(arr2[j] < arr1[i]-d){
//                 j++;
//             }else{
//                 count++;
//                 i++;
//             }
//         }
//         count += arr1.size()-i;
//         return count-1;
//     }
// };

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        int count = 0;
        int i = 0, j = 0;

        while (i < arr1.size()) {
            if (j < arr2.size() && abs(arr1[i] - arr2[j]) <= d) {
                i++;
            } else if (j < arr2.size() && arr2[j] < arr1[i] - d) {
                j++;
            } else {
                count++;
                i++;
            }
        }

        return count;
    }
};
