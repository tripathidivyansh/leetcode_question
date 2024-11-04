// class Solution {
// public:
//     bool isNStraightHand(vector<int>& hand, int groupSize) {
//         int n = hand.size();
//         map<int, int>mp;
//         for(int x : hand){
//             mp[x]++;

//         }
//         for(auto it:mp){
//             if(mp[it.first] > 0){
//                 for(int i = 1; i<groupSize; i++){
//                     mp[it.first + i] -= mp[it.first];
//                     if(mp[it.first + i] < 0){
//                         return false;
//                     }
//                 }
//             }
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) {
            return false;
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[hand[i]]++;
        }
        for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            int startCard = it->first;
            int count = it->second;

            if (count > 0) {
                for (int i = 1; i < groupSize; i++) {
                    int nextCard = startCard + i;
                    mp[nextCard] -= count;
                    if (mp[nextCard] < 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
