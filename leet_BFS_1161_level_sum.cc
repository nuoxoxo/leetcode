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
    int maxLevelSum(TreeNode* root)
    {
        if (! root)
            return 0;
        deque<TreeNode *>   dq{root};
        int record = -2147483648;
        int curr = 0; // current level sum
        int res = 0; // min level no.
        int level = 0;

        int len, i;
        while (!dq.empty())
        {
            ++level;
            len = (int) dq.size();
            curr = 0;
            i = -1;
            while (++i < len)
            {
                TreeNode    *node;

                node = dq.front();
                dq.pop_front();
                curr += node->val;
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
            if (curr > record)
                res = level;
            record = max(curr, record);
        }
        return (res);
    }
};
