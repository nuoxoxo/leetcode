class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
        return (sumBranch(root, 0));
    }

    int sumBranch(TreeNode *root, int n)
    {
        if (!root)                          return (NULL);
        if (!root->left && !root->right)    return (n * 10 + root->val);
        return (sumBranch(root->right, n * 10 + root->val) + sumBranch(root->left, n * 10 + root->val));
    }
};

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
