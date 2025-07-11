class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> lastAvailable(n, 0); 

        vector<int> roomUse(n, 0);             
        for (const vector<int>& meet : meetings) {
            int start = meet[0];
            int end = meet[1];
            int duration = end - start;
            bool found = false;
            for (int room = 0; room < n; ++room) {
                if (lastAvailable[room] <= start) {
                    lastAvailable[room] = end;
                    roomUse[room]++;

                    found = true;
                    break;
                }
            }
            if (!found) {
                int earliestRoom = 0;
                long long earliestTime = lastAvailable[0];
                for (int room = 1; room < n; ++room) {
                    if (lastAvailable[room] < earliestTime) {
                        earliestTime = lastAvailable[room];
                        earliestRoom = room;
                    }
                }
                lastAvailable[earliestRoom] += duration;
                roomUse[earliestRoom]++;
            }
        }
        int resultRoom = 0;

        for (int i = 1; i < n; ++i) {
            if (roomUse[i] > roomUse[resultRoom]) {
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};