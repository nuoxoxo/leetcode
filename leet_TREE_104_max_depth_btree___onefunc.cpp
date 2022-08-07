class Solution {
public:
    int maxDepth(TreeNode* r)
    {
        if (!r)
            return (0);
        return 1 + max(maxDepth(r->left), maxDepth(r->right));
    }
};

/*
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
*/
