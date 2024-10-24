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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        std::function<bool(TreeNode*, TreeNode*)> check = [&](TreeNode* L, TreeNode* R){
            if (!L && !R)
                return true;
            if (!L && R || L && !R || L->val ^ R->val)
                return false;
            return check(L->left, R->left) && check(L->right, R->right) || \
                check(L->left, R->right) && check(L->right, R->left);
        };
        return check(root1, root2);
    }
};
