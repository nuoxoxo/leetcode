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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        int n = (int) nums.size();
        if (!n)
            return NULL;
        if (n == 1)
            return new TreeNode(nums[0]);
        return make_tree(nums, 0, n - 1);
    }

    TreeNode*   make_tree(vector<int> nums, int L, int R)
    {
        TreeNode    *node;
        int         mid;

        if (L > R)
            return NULL;

        mid = (R - L) / 2 + L;
        node = new TreeNode(nums[mid]);
        node->left = make_tree(nums, L, mid - 1);
        node->right = make_tree(nums, mid + 1, R);
        return node ;
    }
};
