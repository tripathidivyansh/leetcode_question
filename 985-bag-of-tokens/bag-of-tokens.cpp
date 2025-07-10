class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int Score = 0, maxScore = 0, l = 0, r = tokens.size()-1;
        
        while(l<=r){
            if(power >= tokens[l]){
                power -= tokens[l++];
                Score++;
                maxScore = max(maxScore,Score);
            }else if(Score > 0){
                power += tokens[r--];
                Score--;
            }else{
                break;
            }
        }
        return maxScore;
    }
};