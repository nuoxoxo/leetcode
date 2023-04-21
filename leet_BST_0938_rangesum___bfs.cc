class Solution {
public:
    int rangeSumBST(TreeNode* root, int lo, int hi)
    { 
        // BFS
        deque<TreeNode *>   D{root};
        vector<int>         v;
        TreeNode    *temp;
        int         n;
        while (!D.empty())
        {
            temp = D.front();
            D.pop_front();
            n = temp->val;
            if (n <= hi && n >= lo)
                v.push_back(n);
            if (temp->left)
                D.push_back(temp->left);
            if (temp->right)
                D.push_back(temp->right);
        }
        return std::accumulate(v.begin(), v.end(), 0);
    }
};
