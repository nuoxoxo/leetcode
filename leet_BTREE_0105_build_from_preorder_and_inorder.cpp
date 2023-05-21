
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        TreeNode    *node;
        int         i;

        node = NULL;
        if (!preorder.size() || !inorder.size())
            return node ;
        node = new TreeNode(preorder[0]);
        i = -1;
        while (++i < inorder.size())
            if (node->val == inorder[i])
                break ;
        vector<int> po1(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> io1(inorder.begin(), inorder.begin() + i + 1);
        vector<int> po2(preorder.begin() + i + 1, preorder.end());
        vector<int> io2(inorder.begin() + i + 1, inorder.end());
        node->left = buildTree(po1, io1);
        node->right = buildTree(po2, io2);
        return node ;
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
