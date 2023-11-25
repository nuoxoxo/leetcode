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
    int averageOfSubtree(TreeNode* root)
    {
        int res = 0;
        deque<TreeNode *>   dq{root};
        while ( ! dq.empty()) // 1st BFS
        {
            int len = (int) dq.size();
            int i = -1;
            while (++i < len)
            {
                TreeNode * node = dq.front();
                dq.pop_front();
                BFS(node, res);
                if (node->left)
                    dq.push_back(node->left);
                if (node->right)
                    dq.push_back(node->right);
            }
        }
        return res;
    }

    void BFS(TreeNode * node, int & res) // 2nd BFS
    {
        int sum_val = 0;
        int sum_node = 0;
        deque<TreeNode *>   dq{ node };
        while (!dq.empty())
        {
            int len = (int) dq.size();
            int i = -1;
            while (++i < len)
            {
                TreeNode * n = dq.front();
                dq.pop_front();
                sum_val += n->val;
                sum_node++;
                if (n->left)
                    dq.push_back(n->left);
                if (n->right)
                    dq.push_back(n->right);
            }
        }
        if (sum_val / sum_node == node->val)
            res++;
    }
};
