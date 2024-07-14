class Solution {
public:
    // bool isUpper(char c) { return isupper(static_cast<unsigned char>(c)); }
    // bool isLower(char c) { return islower(static_cast<unsigned char>(c)); }
    // bool isDigit(char c) { return isdigit(static_cast<unsigned char>(c)); }
    string countOfAtoms(string formula) {
        map<string, int> countMap;
        stack<map<string, int>> stk;
        int i = 0, n = formula.size();
        
        while (i < n) {
            if (formula[i] == '(') {
                stk.push(countMap);
                countMap.clear();
                i++;
            } else if (formula[i] == ')') {
                int j = ++i, val = 0;
                while (j < n && isdigit(formula[j])) j++;
                if (j > i) val = stoi(formula.substr(i, j - i));
                else val = 1;
                i = j;
                
                if (!stk.empty()) {
                    auto tempMap = countMap;
                    countMap = stk.top();
                    stk.pop();
                    for (auto &p : tempMap) {
                        countMap[p.first] += p.second * val;
                    }
                }
            } else {
                int j = i + 1;
                while (j < n && islower(formula[j])) j++;
                string element = formula.substr(i, j - i);
                i = j;
                while (j < n && isdigit(formula[j])) j++;
                int val = (i < j) ? stoi(formula.substr(i, j - i)) : 1;
                countMap[element] += val;
                i = j;
            }
        }
        
        vector<pair<string, int>> elements(countMap.begin(), countMap.end());
        sort(elements.begin(), elements.end());
        
        string result;
        for (auto &p : elements) {
            result += p.first;
            if (p.second > 1) result += to_string(p.second);
        }
        
        return result;
    }
};