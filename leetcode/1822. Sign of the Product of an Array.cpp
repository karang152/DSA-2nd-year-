//https://leetcode.com/problems/sign-of-the-product-of-an-array/submissions/943334734/



class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=0;
        for(auto x : nums){
            if(x<0) n++;
            if(x==0) return 0;
        }
        if(n%2==0)return 1;
        return -1;
    }
};
