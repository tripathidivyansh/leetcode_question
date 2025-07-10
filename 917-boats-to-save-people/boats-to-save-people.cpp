class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0, minCount = INT_MAX, Sum = 0;

        int l = 0, r = people.size()-1;
        while(l <=r){
            if(people[l] + people[r] <= limit){
                l++;
                r--;
            }else{

                r--;
            }
            count++;
            minCount = min(minCount, count);
        }

        return count;
    }
};