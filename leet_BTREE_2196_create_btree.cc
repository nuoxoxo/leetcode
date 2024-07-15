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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        // description -> parent-child relation
        unordered_map<int, TreeNode *> nodes;
        unordered_set<int> ischild;
        for (auto t : descriptions)
        {
            int parent = t[0];
            int child = t[1];
            int isleft = t[2];
            if (nodes[parent] == nullptr)
                nodes[parent] = new TreeNode(parent);
            if (nodes[child] == nullptr)
                nodes[child] = new TreeNode(child);
            if (isleft)
                nodes[parent]->left = nodes[child];
            else
                nodes[parent]->right = nodes[child];
            ischild.insert(child);
        }
        TreeNode * res = nullptr;
        for (auto p : nodes)
        {
            if (ischild.find(p.first) == end(ischild))
            {
                res = p.second;
                break ;
            };
        }
        return res;
    }
};
