//https://leetcode.com/problems/spiral-matrix-ii/submissions/947929105/




class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int SR = 0, ER = n - 1, SC = 0, EC = n - 1, total = n * n, cnt = 1;

        while (cnt <= total) {
            for (int i = SC; i <= EC && cnt <= total; i++) {
                result[SR][i] = cnt;
                cnt++;
            }
            SR++;
            
            for (int i = SR; i <= ER && cnt <= total; i++) {
                result[i][EC] = cnt;
                cnt++;
            }
            EC--;
            
            for (int i = EC; i >= SC && cnt <= total; i--) {
                result[ER][i] = cnt;
                cnt++;
            }
            ER--;
            
            for (int i = ER; i >= SR && cnt <= total; i--) {
                result[i][SC] = cnt;
                cnt++;
            }
            SC++;
        }

        return result;
    }
};
