class Solution {
public:
    TreeNode* searchBST(TreeNode* node, int val)
    {
        if (!node)              return NULL ;
        if (val == node->val)   return node ;
        if (val > node->val)    return searchBST(node->right, val);
        else                    return searchBST(node->left, val);
    }
}
