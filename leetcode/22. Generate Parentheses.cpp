//   https://leetcode.com/problems/generate-parentheses/submissions/942189314/


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        fun(ans,n,0,0,"");
        return ans;
    }
    void fun(vector<string>&ans,int n,int open,int close,string curr_str) {
        // base case
        if(curr_str.size()==n*2){
            ans.push_back(curr_str);
        }
        if(open<n) fun(ans,n,open+1,close,curr_str+"(");
        if(close<open) fun(ans,n,open,close+1,curr_str+")");

    }
};
