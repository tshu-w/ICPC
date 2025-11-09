/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int distance, vector<int>& cnt) {
        if (node == nullptr) return 0;
        if (node->left == nullptr && node->right == nullptr) {
            cnt[0] = 1;
            return 0;
        }
        int ans = 0;
        vector<int> cnt1(11, 0), cnt2(11, 0);
        ans += dfs(node->left, distance, cnt1);
        ans += dfs(node->right, distance, cnt2);

        for (int i = 10; i >= 1; i--) {
            cnt1[i] = cnt1[i - 1];
            cnt2[i] = cnt2[i - 1];
            cnt[i] = cnt1[i] + cnt2[i];
        }
        cnt1[0] = cnt2[0] = 0;

        for (int i = 1; i < distance; i++) {
            int sum = 0;
            for (int j = 1; j <= distance - i; j++)
                sum += cnt2[j];

            ans += cnt1[i] * sum;
        }
        return ans;
    }
    int countPairs(TreeNode* root, int distance) {
        vector<int> cnt(11, 0);
        return dfs(root, distance, cnt);
    }
};
