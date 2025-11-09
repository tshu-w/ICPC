class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() <= 1) return;

        int pos = nums.size() - 2;
        while (pos >= 0 && nums[pos] >= nums[pos + 1]) pos--;
        if (pos == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int pos2 = nums.size() - 1;
        while (pos2 >= pos && nums[pos2] <= nums[pos])
            pos2--;

        swap(nums[pos], nums[pos2]);

        reverse(nums.begin() + pos + 1, nums.end());

        return;
    }
};
