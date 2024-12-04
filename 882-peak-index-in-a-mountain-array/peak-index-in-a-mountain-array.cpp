class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        // int max = INT_MIN;

        // for(int i = 1; i<=n; i++){
        //     if(arr[i]> max){
        //         max = arr[i];
        //         return i;
        //     }
        // }
        // return -1;
        int low = 0, high = arr.size()-1;
        while(low < high){
            int mid = (low+high)/2;
            
            if(arr[mid] > arr[mid+1]){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};