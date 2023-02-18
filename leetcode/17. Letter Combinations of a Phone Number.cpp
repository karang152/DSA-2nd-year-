//https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/900455034/




class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        
        vector<string> result;
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string combination = "";
        
        backtrack(result, mapping, digits, combination, 0);
        
        return result;
    }
    
private:
    void backtrack(vector<string>& result, vector<string>& mapping, string& digits, string& combination, int index) {
        if (index == digits.length()) {
            result.push_back(combination);
            return;
        }
        
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            combination.push_back(letter);
            backtrack(result, mapping, digits, combination, index + 1);
            combination.pop_back();
        }
    }
};
