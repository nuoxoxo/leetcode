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
    int minCameraCover(TreeNode* root)
    {
        int count = 0;
        if (!dfs(root, &count))
            return count + 1;
        return count;
    }

    int dfs(TreeNode* node, int* count)
    {
        if (!node)
            return 1;
        int a = dfs(node->left, count);
        int b = dfs(node->right, count);
        if (!a || !b)
        {
            ++(*count);
            return 2;
        }
        if (a == 1 && b == 1)
            return 0;
        return 1;
    }
};
