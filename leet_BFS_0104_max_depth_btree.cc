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
    int maxDepth(TreeNode* root)
    {
        int res = 0;
        if (! root)
            return res;
        deque<TreeNode *>   D{root};
        // cout << D.size() << endl;
        while (!D.empty())
        {
            int         len = D.size();
            while (--len > -1)
            {
                TreeNode    *node = D.front();

                D.pop_front();
                if (node->left)
                    D.push_back(node->left);
                if (node->right)
                    D.push_back(node->right);
            }
            ++res;
        }
        return res;
    }
};
