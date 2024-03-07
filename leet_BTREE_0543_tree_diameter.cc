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
        depth(root, res);
        return res;
    }
    int depth (TreeNode * node, int & n) {
        if (!node)
            return 0;
        int L = depth(node->left, n);
        int R = depth(node->right, n);
        n = L + R > n ? L + R : n;
        int curr = L > R ? L : R;
        return 1 + curr;
    }
};
