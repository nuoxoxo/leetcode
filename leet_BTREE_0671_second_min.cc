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
    int findSecondMinimumValue(TreeNode* root)
    {
        vector<int (*) (TreeNode *)> Solutions {
            // BFS_with_set,
            BFS_economic,
            // DFS,
        };
        return Solutions[0](root);
    }

    static int DFS(TreeNode * root)
    {
        long long res[2] = {2147483648, 2147483648};

        std::function<void(TreeNode *, long long[2])> recurse = [&](TreeNode * node, long long res [2])
        {
            if (!node)
                return ;
            int n = node->val;
            if (n < res[0])
            {
                res[1] = res[0];
                res[0] = n;
            }
            else if (n ^ res[0] && n < res[1])
            {
                res[1] = n;
            }
            recurse(node->left, res);
            recurse(node->right, res);
        };

        recurse(root, res);
        return res[1] ^ 2147483648 ? (int) res[1] : -1;
    }

    static int BFS_economic(TreeNode * root)
    {

        long long res[2] = {2147483648, 2147483648};

        deque<TreeNode *> Q {root};        
        bool flag0 = false, flag1 = false;
        while (!Q.empty())
        {
            TreeNode * node = Q.front();
            int n = node->val;
            Q.pop_front();
            if (n < res[0])
            {
                res[1] = res[0];
                res[0] = n;
            }
            else if (n ^ res[0] && n < res[1])
            {
                res[1] = n;
            }
            if (node->left)
                Q.push_back(node->left);
            if (node->right)
                Q.push_back(node->right);
        }
        return res[1] ^ 2147483648 ? (int) res[1] : -1;
    }

    static int BFS_with_set(TreeNode * root)
    {
        deque<TreeNode *> Q {root};
        // int res[2] = {2147483647, 2147483647};
        unordered_set<int> S;
        while (!Q.empty())
        {
            TreeNode * node = Q.front();
            int n = node->val;
            Q.pop_front();
            S.insert(n);
            if (node->left)
                Q.push_back(node->left);
            if (node->right)
                Q.push_back(node->right);
        }
        vector<int> vi(S.begin(), S.end());
        if (vi.size() < 2)
            return -1;
        sort(vi.begin(), vi.end());
        return vi[1];
    }
};
