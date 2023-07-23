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
    vector<TreeNode*> allPossibleFBT(int n)
    {
        if (n == 1)
            return { new TreeNode() };
        if (n % 2 == 0)
            return {};

        vector<TreeNode *>  res;
        int i = 1;
        while (i < n - 1)
        {
            vector<TreeNode *>  L = allPossibleFBT(i);
            vector<TreeNode *>  R = allPossibleFBT(n - i - 1);
            for (TreeNode *l: L)
            {
                for (TreeNode *r: R)
                {
                    TreeNode    *node = new TreeNode();
                    node->left = l;
                    node->right = r;
                    res.push_back(node);
                }
            }
            i += 2;
        }
        return res;
    }
};

