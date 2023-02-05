//https://leetcode.com/problems/zigzag-conversion/submissions/1





class Solution {

public:

    string convert(string s, int numRows) {

        if (numRows == 1 || numRows >= s.length()) {

            return s;

        }

        

        vector<string> rows(numRows);

        int index = 0, step = 1;

        

        for (char c : s) {

            rows[index] += c;

            if (index == 0) {

                step = 1;

            } else if (index == numRows - 1) {

                step = -1;

            }

            index += step;

        }

        

        string result;

        for (string row : rows) {

            result += row;

        }

        

        return result;

    }

};

