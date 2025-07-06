class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq2;
    FindSumPairs(vector<int>& n1, vector<int>& n2) {

        nums1 = n1;
        nums2 = n2;
        for (int num : nums2) {
            freq2[num]++;
        }
    }
    void add(int index, int val) {
        if (index >= 0 && index < nums2.size()) {
            freq2[nums2[index]]--; 
            nums2[index] += val;
            freq2[nums2[index]]++; 
        }
    }
    int count(int tot) {
        int cnt = 0;
        for (int a : nums1) {
            int b = tot - a;
            if (freq2.count(b)) {
                cnt += freq2[b];
            }
        }
        return cnt;
    }
};
