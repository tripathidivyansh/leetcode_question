class Solution {
public:
    int getPivot(vector<int>& nums, int n) {
        int S = 0, e = n - 1;
        while (S < e) {
            int mid = S + (e - S) / 2;
            if (nums[mid] >= nums[0]) {
                S = mid + 1;
            } else {
                e = mid;
            }
        }
        return S;
    }

    int binarySearch(vector<int>& nums, int S, int e, int target) {
        while (S <= e) {
            int mid = S + (e - S) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                S = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivot = getPivot(nums, n);

        if (target >= nums[pivot] && target <= nums[n - 1]) {
            return binarySearch(nums, pivot, n - 1, target);
        } else {
            return binarySearch(nums, 0, pivot - 1, target);
        }
    }
};