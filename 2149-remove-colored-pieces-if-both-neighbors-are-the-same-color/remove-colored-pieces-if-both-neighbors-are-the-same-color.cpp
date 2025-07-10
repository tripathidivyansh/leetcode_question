class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size() <= 2) return false;
        int count_a = 0 , count_b = 0;

        int n = colors.size();
        for(int i = 1; i<n-1; i++){
            if(colors[i] == 'A' && colors[i-1] == 'A' && colors[i+1] == 'A'){
                count_a++;
            }else if(colors[i] == 'B'  && colors[i-1]  == 'B' &&  colors[i+1] == 'B'){
                count_b++;
            }
        }
        return count_a > count_b;
    }
};