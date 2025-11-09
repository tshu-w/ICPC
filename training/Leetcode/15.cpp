class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    ans.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    while (l < r && nums[l + 1] == nums[l]) l++;
                    while (l < r && nums[r - 1] == nums[r]) r--;
                    l++; r--;
                } else if (nums[i] + nums[l] + nums[r] < 0) {
                    l++;
                } else {
                    r--;
                }
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) i++;
        }
        return ans;
    }
};
