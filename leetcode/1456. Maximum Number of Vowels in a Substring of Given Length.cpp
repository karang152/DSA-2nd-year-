//https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/submissions/944934958/




class Solution {
public:
    int maxVowels(string s, int k) {
        int count=0,temp=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') temp++;
            if(i-k>=0){
                if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u') temp--;
            }
            if(temp>count)count=temp;
        }
        return count;
        
    }
};
