
class Solution {
public:
    bool isValidBST(TreeNode* root)
    {
        vector<int> group;
        inorder(root, group);
        print_vi(group);
        int i = 0;
        while (++i < group.size())
            if (group[i - 1] >= group[i])
                return false;
        return true;
    }

    void    inorder(TreeNode *node, vector<int>& n)
    {
        if (!node)
            return ;
        inorder(node->left, n);
        n.push_back(node->val);
        inorder(node->right, n);
    }

    void    print_vi(vector<int> nums)
    {
        for (int n : nums)
            cout << n << endl;
        cout << endl;
    }
};

/*

[1,2,3,4,5,null,null]

*/

/*

Inorder Algorithm
   1. Traverse the left subtree, i.e., call Inorder(left-subtree)
   2. Visit the root.
   3. Traverse the right subtree, i.e., call Inorder(right-subtree)

*/


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
