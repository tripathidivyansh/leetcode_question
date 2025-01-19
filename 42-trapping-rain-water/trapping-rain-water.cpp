class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        int water = 0;
        int left = 0, right = height.size()-1;
        int leftmax = 0 , rightmax = 0;

        while(left<=right){
            if(height[left] <height[right]){
                if(height[left] > leftmax){
                    leftmax = height[left];
                }else{
                    water += leftmax- height[left];
                }
                left++;
            }else{
                if(height[right] >= rightmax){
                    rightmax = height[right];
                }else{
                    water += rightmax - height[right];
                }
                right--;
            }
        }
        return water;
    }
};

























































































// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         if(n==0) return 0;
//         int leftmax = 0, rightmax =0;
//         int left = 0, right = n-1;
//         int water = 0;
//         while(left <=right){
//             if(height[left] <height[right]){
//                 if(height[left] > leftmax){
//                     leftmax = height[left];
//                 }else{
//                     water += leftmax-height[left];
//                 }
//                 left++;
//             }else{
//                 if(height[right] >= rightmax){
//                     rightmax = height[right];
//                 }else{
//                     water += rightmax-height[right];
//                 }
//                 right--;
//             }

//         }
//         return water;
//     }
// };


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int n = height.size();
//         int water = 0;

//         for(int i = 0; i<n; i++){
//             int j = i;
//             int leftmax = 0, rightmax = 0;
//             while(j>=0){
//                 leftmax = max(leftmax, height[j]);
//                 j--;
//             }
//             j = i;
//             while(j<n){
//                 rightmax = max(rightmax, height[j]);
//                 j++;
//             }
//             water += min(leftmax, rightmax)-height[i];
//         }
//         return water;
//     }
// };