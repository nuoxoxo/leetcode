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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        deque<TreeNode *>   dq = {root};
        vector<long long>   res;
        while (!dq.empty())
        {
            long long   level = 0;
            int len = (int) dq.size();
            while (len--)
            {
                TreeNode *node = dq.front();
                level += node->val;
                dq.pop_front();
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
            res.push_back(level);   
        }
        int n = (int) res.size();
        if (n < k)
            return -1;
        sort(res.rbegin(), res.rend());
        return res[k - 1];

        // idem
        // sort(res.begin(), res.end());
        // return res[n - k];
    }
};
