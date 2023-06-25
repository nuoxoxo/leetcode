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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums)
    {
        deque<TreeNode *>   D;
        int i = -1;
        while (++i < (int) nums.size())
        {
            TreeNode    *node = new TreeNode(nums[i]);
            while (!D.empty() && nums[i] > D.front()->val)
            {
                node->left = D.front();
                D.pop_front();
            }
            if (!D.empty())
            {
                D.front()->right = node;
            }
            D.push_front(node);
        }
        while (D.size() > 1)
        {
            D.pop_front();
        }
        return D.front();
    }
};
