//https://leetcode.com/problems/3sum-closest/submissions/899881761/



class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(closest_sum - target)) {
                    closest_sum = sum;
                }
                if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        
        return closest_sum;
    }
};
