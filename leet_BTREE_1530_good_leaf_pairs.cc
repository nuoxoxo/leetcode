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
    int countPairs(TreeNode* root, int distance)
    {
        int res = 0;
        unordered_map<TreeNode *, unordered_map<int, int>> cache;
        unordered_map<TreeNode *, bool> hasCache;
        std::function<unordered_map<int, int>(TreeNode *)> DFS = [&](TreeNode* node)
        {
            if (node == nullptr)
                return unordered_map<int, int>{};
            if (hasCache[node])
                return cache[node];
            auto L = DFS(node->left);
            auto R = DFS(node->right);
            if (L.empty() && R.empty())
            {
                auto ret = unordered_map<int, int>{{0, 1}};
                hasCache[node] = true;
                cache[node] = ret;
                return ret;
            }
            for (auto l : L)
                for (auto r : R)
                    if (l.first + 1 + r.first + 1 <= distance)
                        res += l.second * r.second;
            unordered_map<int, int> counter;
            for (auto l : L)
                counter[l.first + 1] += l.second;
            for (auto r : R)
                counter[r.first + 1] += r.second;
            hasCache[node] = true;
            cache[node] = counter;
            return counter;
        };
        DFS(root);
        return res;
    }
};
