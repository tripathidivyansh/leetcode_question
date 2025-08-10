class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalgaS = 0, totalcoSt = 0;
        int tank = 0;
        
        int Start = 0;
        int n = gas.size();
        for(int i = 0; i<n; i++){
            totalgaS += gas[i];
            totalcoSt += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                Start = i+1;
                tank = 0;
            }
        }
        if(totalgaS >= totalcoSt) return Start;
        return -1;
    }
};