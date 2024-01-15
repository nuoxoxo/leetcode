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
    int maxAncestorDiff(TreeNode* root) {

        int ( * Solutions [] )( TreeNode *, int, int ) = { BFS, DFS };
        return Solutions[ std::rand() % 2 ]( root, root->val, root->val );
    }

    // BFS

    static int BFS(TreeNode * node, int L, int R) {
        std::deque<std::tuple< TreeNode *, int, int>> D{ {node, L, R} };
        int res = 0;
        while ( ! D.empty() ) {
            std::tuple<TreeNode *, int, int> tpl = D.front();
            D.pop_front();
            node = get<0>(tpl);
            L = get<1>(tpl);
            R = get<2>(tpl);
            L = min(L, node->val);
            R = max(R, node->val);
            if (node->left)
                D.push_back( {node->left, L, R} );
            if (node->right)
                D.push_back( {node->right, L, R} );
            res = max(res, R - L);
        }
        return res;
    }

    // DFS

    static int DFS (TreeNode * node, int L, int R) {
        if ( ! node)
            return R - L;
        L = min(L, node->val);
        R = max(R, node->val);
        return max(
            DFS(node->left, L, R),
            DFS(node->right, L, R)
        );
    }
};
