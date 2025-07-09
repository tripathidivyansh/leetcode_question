class Solution {
public:
    void solve(string &curr, string& tiles, vector<bool>& used, unordered_set<string>& resultS) {
        resultS.insert(curr);  

        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;

            used[i] = true;
            curr.push_back(tiles[i]);
            solve(curr, tiles, used, resultS);
            curr.pop_back();
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        vector<bool> used(n, false);
        unordered_set<string> resultS;
        string curr = "";

        solve(curr, tiles, used, resultS);

        return resultS.size() - 1; 
    }
};
