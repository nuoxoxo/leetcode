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
    string tree2str(TreeNode* root) {
        return preorder( root );
    }
    std::string preorder(TreeNode * node) {
        if (!node)
            return "";
        std::string res = to_string(node->val);
        if (node->left)
            res += '(' + preorder(node->left) + ')';
        if (node->right)
        {
            if (!node->left)
                res += "()";
            res += '(' + preorder(node->right) + ')';
        }
        return res;
    }

    // way 2
    /*
    string tree2str(TreeNode* node ) {//root) {
        if ( !node)
            return "";
        string res = to_string(node->val);
        string L = tree2str(node->left);
        string R = tree2str(node->right);
        if (L == "" and R != "")
            res += "()";
        if (L != "")
            res += "(" + L + ")";
        if (R != "")
            res += "(" + R + ")";
        return res;
    }
    */
};
