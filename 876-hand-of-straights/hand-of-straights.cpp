class Solution {
public:
    bool check(vector<int>& hand, int groupSize, int i){
        int n = hand.size();
        int x = hand[i];
        hand[i] = -1;
        int count = 1;
        i++;
        while(count < groupSize && i < n){
            if(hand[i] == (x+1)){
                count++;
                x++;
                hand[i] = -1;
                i = 0; 
            } else {
                i++;
            }
        }
        if(count == groupSize){
            return true;
        }
        return false;
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize){
            return false;
        }
        sort(hand.begin(), hand.end());
        for(int i = 0; i < n; i++){
            if(hand[i] != -1){ 
                if(check(hand, groupSize, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};
