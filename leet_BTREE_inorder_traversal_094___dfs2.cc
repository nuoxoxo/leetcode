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
private:
    vector<int> E;
public:
    vector<int> inorderTraversal(TreeNode* node)
    {
        if (!node)
            return E ;
        inorderTraversal(node->left);
        E.push_back(node->val);
        inorderTraversal(node->right);
        return E ;
    }
};
