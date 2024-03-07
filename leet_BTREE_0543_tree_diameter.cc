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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dive(root, res);
        return res;
    }

    int dive(TreeNode * node, int & res)
    {
        if (!node)
            return 0;
        int L = dive(node->left, res);
        int R = dive(node->right, res);
        res = max(res, L + R);
        return max(L, R) + 1;
    }
};
