class Solution {
public:
    void solve(string &word, int k) {
        if (word.size() >= k) {
            return;
            
        }

        string nextpart = "";
        for (char c : word) {
            if (c == 'z') {
                nextpart += 'a';
            } else {
                nextpart += c + 1;
            }
        }


        word += nextpart;
        solve(word, k);
    }

    char kthCharacter(int k) {
        string word = "a";
        solve(word, k);
        return word[k - 1];
    }
};
