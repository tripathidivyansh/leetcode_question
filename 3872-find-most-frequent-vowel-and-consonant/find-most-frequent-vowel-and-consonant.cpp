class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char, int> freq;
        for(char c : s) {
            freq[c]++;
        }        
        string vowels = "aeiou";
        unordered_set<char> vowelSet(vowels.begin(), vowels.end());
        int maxVowel = 0, maxConsonant = 0;
        
        for(auto &p : freq) {
            char ch = p.first;
            int f = p.second;
            if(vowelSet.count(ch)) {
                maxVowel = max(maxVowel, f);
            } else {
                maxConsonant = max(maxConsonant, f);
            }
        }
        return maxVowel + maxConsonant;

    }
};





































































































































































































