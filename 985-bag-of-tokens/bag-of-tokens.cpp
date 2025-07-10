class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int Score = 0, maxScore = 0, i = 0, j = tokens.size()-1;
        
        while(i <= j){
            if(power >= tokens[i]){
                power -= tokens[i++];
                Score++;
                maxScore = max(maxScore, Score);
            }else if(Score > 0){
                power += tokens[j--];
                Score--;
            }else{
                break;
            }
        }
        return maxScore;
    }
};