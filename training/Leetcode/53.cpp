class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MIN);
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                dp[i] = nums[i];
            } else {
                dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, dp[i]);
        }
        if (ans == INT_MIN)
            return -1;
        return ans;
    }
};
