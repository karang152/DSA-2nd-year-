//https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/submissions/943342962/




class Solution {
public:
    double average(vector<int>& salary) {
        double total=0;
        int minimum=INT_MAX,maximum=INT_MIN;
        for(int i=0;i<salary.size();i++){
            total+=salary[i];
            minimum=min(minimum,salary[i]);
            maximum=max(maximum,salary[i]);
        }
        total-=(minimum+maximum);
        return total/(salary.size()-2);
    }
};
