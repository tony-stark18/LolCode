int IO = []{
    ios::sync_with_stdio(false); cin.tie(nullptr); return 0;
}();
class Solution {
public:
    void sortS(vector<int>& skill) {
        int maxEl = *max_element(skill.begin(), skill.end());;
        vector<int> freq(maxEl + 1, 0);
        for (int i : skill) {
            freq[i]++;
        }
        int k = 0;
        for (int i = 0; i <= maxEl; i++) {
            while (freq[i]--) {
                skill[k++] = i;
            }
        }
    }
    long long dividePlayers(vector<int>& skill) {
        sortS(skill);
        int i = 0;
        int j = skill.size() - 1;

        long long sum = skill[i] + skill[j];
        long long chemistry = 0;

        while (i < j) {
            if (skill[i] + skill[j] != sum) {
                return -1; 
            }
            chemistry += (skill[i] * skill[j]);
            i++;
            j--;
        }

        return chemistry;
    }
};