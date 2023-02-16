//https://leetcode.com/problems/sum-of-unique-elements/submissions/899024328/




class Solution {

public:

    int sumOfUnique(vector<int>& nums) {

        unordered_map<int, int> count;

        for (int num : nums) {

            count[num]++;

        }

        int sum = 0;

        for (auto it : count) {

            if (it.second == 1) {

                sum += it.first;

            }

        }

        return sum;

    }

};
