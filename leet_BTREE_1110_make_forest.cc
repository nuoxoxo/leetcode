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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete)
    {
        vector<TreeNode*> res;
        fillForestDFS(res, to_delete, root, false);
        // doesNotReturn(res, to_delete, root, false);
        return res;
    }

    static bool has(vector<int>& arr, int tar) {
        return find(begin(arr), end(arr), tar) != end(arr);
    }

    static void doesNotReturn(
        vector<TreeNode*>&res, vector<int>& to_delete, TreeNode * node, bool hasParent
    )
    {
        if (!node)
            return ;
        bool validParent = true;
        if (find(begin(to_delete), end(to_delete), node->val) != end(to_delete))
            validParent = false;
        if (validParent && !hasParent)
            res.push_back(node);
        doesNotReturn(res, to_delete, node->left, validParent);
        doesNotReturn(res, to_delete, node->right, validParent);
        if (node->left && has(to_delete, node->left->val))
            node->left = nullptr;
        if (node->right && has(to_delete, node->right->val))
            node->right = nullptr;
    }

    static TreeNode * fillForestDFS(
        vector<TreeNode*>&res,
        vector<int>& to_delete,
        TreeNode * node,
        bool hasParent
    )
    {
        if (!node)
            return nullptr;
        TreeNode * new_parent = node;
        if (has(to_delete, node->val))
            new_parent = nullptr;
        if ( ! hasParent && new_parent)
            res.push_back(new_parent);
        node->left = fillForestDFS(res, to_delete, node->left, (new_parent != nullptr));
        node->right = fillForestDFS(res, to_delete, node->right, (new_parent != nullptr));
        return new_parent;
    }
};
