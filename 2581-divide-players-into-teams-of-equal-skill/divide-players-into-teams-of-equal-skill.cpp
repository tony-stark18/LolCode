class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i = 0;
        int j = skill.size()-1;
        long long sum = skill[i]+skill[j];
        long long chemistry = skill[i]*skill[j];
        i++;
        j--;
        while(i<j){
            if(skill[i]+skill[j]!=sum){
                return -1;
            }
            chemistry += (skill[i]*skill[j]);
            i++;
            j--; 
        }
        return chemistry;
    }
};