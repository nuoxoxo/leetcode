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
    vector<int> largestValues(TreeNode* root)
    {
        if (!root)
            return {} ;
        deque<TreeNode *>   D = { root };
        vector<int> res;
        while (!D.empty())
        {
            // vector<int> temp;
            // for (TreeNode * node: D)
            //     temp.push_back(node->val);
            // res.push_back(*max_element(temp.begin(), temp.end()));
            int len = (int) D.size();
            int temp = -2147483648;
            while (len--)
            {
                TreeNode * node = D.front();
                D.pop_front();
                temp = max(temp, node->val);
                if (node->left)
                    D.push_back(node->left);
                if (node->right)
                    D.push_back(node->right);
            }
            res.push_back(temp);
        }
        return res;
    }
};
