class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        return (maxN(root, 0));
    }
    
    int maxN(TreeNode* p, int n)
    {
        if (!p) return (n); 
        int L = maxN(p->left, n + 1);
        int R = maxN(p->right, n + 1);
        int N = L > R ? L : R;
        return (N);
    }
};

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
