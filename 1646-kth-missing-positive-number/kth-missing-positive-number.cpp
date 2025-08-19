class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // int n = arr.size();
        // for(int i = 0; i<n; i++){

        //     if(arr[i] <= k){
        //        k++; 
        //     }else{
        //         break;
        //     }
        // }
        
        // return k;
        int n = arr.size();
        int l = 0, r = n-1;

        while(l<=r){
            int mid = l + (r-l)/2;
            int kinte_mSSingSS = arr[mid] - (mid+1);
            if(kinte_mSSingSS < k){
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return l + k;
    }
};



