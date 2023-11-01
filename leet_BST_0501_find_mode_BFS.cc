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
    vector<int> findMode(TreeNode* root)
    {
        if (!root)
            return {} ;
        vector<int> res;
        deque<TreeNode *>   dq{root};
        unordered_map<int, int> mp;
        int occ = 0; // max occurence of modes
        while (!dq.empty())
        {
            TreeNode * node = dq.front();
            dq.pop_front();
            mp[node->val] ++;
            occ = std::max(occ, mp[node->val]);
            if (node->left)
                dq.push_back(node->left);
            if (node->right)
                dq.push_back(node->right);
        }
        for (pair<int, int> p: mp)
        {
            if (p.second == occ)
                res.push_back(p.first);
        }
        return res;
    }
};
