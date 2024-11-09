class Solution {
public:
    void generateCombinations(int ind, string digits, string s, vector<string> &res, string combos[]) {
        if(digits.size() == 0) return;
        if(ind == digits.size()) {
            res.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < combos[digit].size(); i++) {
            generateCombinations(ind + 1, digits, s + combos[digit][i], res, combos);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        generateCombinations(0, digits, "", res, combos);
        return res;
    }
};
