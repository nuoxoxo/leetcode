class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        vector<int(*)(TreeNode *, int, int)> Solutions {
            // BFS,
            DFS,
        };
        return Solutions [0](root, low, high);
    }

    static int BFS(TreeNode* root, int low, int high)
    {
        assert( root );
        deque<TreeNode *> D{root};
        vector<int> vi;
        while ( ! D.empty())
        {
            TreeNode * node = D.front();
            D.pop_front();
            int n = node->val;
            if (low <= n && n <= high)
                vi.push_back(n);
            if (node->left)
                D.push_back(node->left);
            if (node->right)
                D.push_back(node->right);
        }
        return std::accumulate(vi.begin(), vi.end(), 0);
    }

    static int DFS(TreeNode * root, int low, int high)
    {
        int res = 0;
        std::function< void(TreeNode *) > recurse = [&](TreeNode * node)
        {
            if ( ! node)
                return ;
            int n = node->val;
            if (low <= n && n <= high)
                res += n;
            if (low < n)
                recurse(node->left);
            if (n < high)
                recurse(node->right);
        };
        recurse( root );
        return res;
    }
};
