class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int bucekt = capacity;
        int count = 0;

        for(int i = 0; i<plants.size(); i++){
            if(bucekt < plants[i]){
                count +=2*i;
                bucekt = capacity;
            }
            bucekt -= plants[i];
            count++;
        }
        return count;
    }
};
