class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        int m = heights.size();

        // vector<pair<int, string>>people;
        // for(int i = 0; i<n; i++){
        //     people.push_back({heights[i], names[i]});
        // }
        // sort(people.begin(), people.end(), [](pair<int,string>&a, pair<int,string>&b){
        //     return a.first > b.first;
        // });

        // vector<string>result;
        // for(auto &malik : people){
        //     result.push_back(malik.second);
        // }
        // return result;


        vector<pair<int, string>>people;
        for(int i = 0; i<n; i++){
            people.push_back({heights[i], names[i]});
        }
        sort(people.begin(), people.end(), [](pair<int,string>&a, pair<int,string>&b){
            return a.first > b.first;
        });
        vector<string>result;
        for(auto malik : people){
            result.push_back(malik.second);
        }
        return result;
    }
};