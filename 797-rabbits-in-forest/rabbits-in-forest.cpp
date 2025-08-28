class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // int Sum = 0;
        // sort(answers.begin(), answers.end());

        // for(int i = 0; i<answers.size(); i++){
        //     int count = 1;
        //     while(i+1 < answers.size() && answers[i] == answers[i+1]){
        //         count++;
        //         i++;
        //     }
        //     int groupSize = answers[i] + 1;
        //     int group = (count + groupSize - 1)/ groupSize;
        //     Sum += group* groupSize;
        // }
        
        // return Sum;
        unordered_map<int,int>mp;
        for(int &x: answers){
            mp[x]++;
        }
        int total = 0;
        for(auto &it : mp){
            int x = it.first;
            int count = it.second;
            int groupSize = x + 1;
            int groupS = ceil((double) count / groupSize);
            total += groupS * (groupSize);
        }
        return total;
    }
};