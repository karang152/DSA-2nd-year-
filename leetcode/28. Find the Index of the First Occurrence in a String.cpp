//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/947355380/




class Solution {
public:
    int strStr(string haystack, string needle) {
        string str = needle;
        int index = haystack.find(str);
        return index;
    }
};
