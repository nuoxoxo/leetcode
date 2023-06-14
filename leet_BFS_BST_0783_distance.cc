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
    int minDiffInBST(TreeNode* root)
    {
        deque<TreeNode*>    dq = {root};
        vector<int>         n;
        while (!dq.empty())
        {
            TreeNode    *node = dq.front();
            dq.pop_front();
            n.push_back(node->val);
            if (node->left)
                dq.push_back(node->left);
            if (node->right)
                dq.push_back(node->right);
        }

        int len = (int) n.size();
        int res = 2147483647;
        int i = -1;
        sort(n.begin(), n.end());
        while (++i < len - 1)
        {
            int tmp = n[i + 1] - n[i];
            res > tmp ? res = tmp : res = res;
        }
        return res;
    }
};
