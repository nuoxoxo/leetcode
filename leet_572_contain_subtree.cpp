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
    bool isSame(TreeNode* root, TreeNode* sample)
    {
        if (!root && !sample)
            return true ;
        if (!root || !sample)
            return false ;
        if (root->val != sample->val)
            return false ;
        return (isSame(root->left, sample->left) &&
                isSame(root->right, sample->right));
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot)
    {
        if (!root && !subRoot)
            return true ;
        if (!root || !subRoot)
            return false;
        if (root->val == subRoot->val)
        {
            if (isSame(root, subRoot))
                return true ;
        }
        if (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot))
            return true ;
        return false ;
    }
};
