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
    TreeNode* invertTree(TreeNode* root) {
        deque<TreeNode*>    D{root};
        if (!root)
            return root;
        while (!D.empty())
        {
            int len = D.size(), i = -1;
            TreeNode    *node = D.front();
            D.pop_front();
            // if (node->left && node->right)
            //     swap(node->left->val, node->right->val);
            swap(node->left, node->right);
            if (node->left)
                D.push_back(node->left);
            if (node->right)
                D.push_back(node->right);
        }
        return root;
    }
};
