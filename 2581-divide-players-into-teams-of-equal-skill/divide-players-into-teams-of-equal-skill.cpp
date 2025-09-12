class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int i = 0, j = skill.size() - 1;

        long long total = 0;
        int target = skill[i] + skill[j];  
        while (i < j) {
            if (skill[i] + skill[j] != target) {

                return -1; 
            }
            total +=  skill[i] * skill[j];
            i++;
            j--;
        }
        return total;
    }
};

