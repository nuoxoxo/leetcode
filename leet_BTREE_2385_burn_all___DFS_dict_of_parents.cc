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
    int amountOfTime(TreeNode* root, int start) {

        // step 1/3 : get the node we need to go from
        TreeNode * snode = DFS_get_starting_point (root, start);
        assert (snode->val == start);

        // step 2/3 : use a map to record all parents
        unordered_map<TreeNode *, TreeNode *> parents;
        DFS_prepare_parents(root, nullptr, parents);
        assert (parents[root] == nullptr);
        if (root->left) assert (parents[root->left] == root);

        // step 3/3 : DFS
        // visualization - 
        //  the problem is equivalent to asking 
        //  what is the longest distance from any node
        set<TreeNode *> seen;
        return DFS_max_dist_from( snode, parents, seen ) - 1;
    }

    int DFS_max_dist_from (TreeNode * node,
        unordered_map<TreeNode *, TreeNode *> & parents,
        set<TreeNode *> & seen) {
        if (!node || seen.find(node) != seen.end())
            return 0;
        seen.insert(node);
        int p = DFS_max_dist_from (parents[node], parents, seen);
        int l = DFS_max_dist_from (node->left, parents, seen);
        int r = DFS_max_dist_from (node->right, parents, seen);
        return 1 + std::max({ p, l, r });
    }

    void DFS_prepare_parents (TreeNode * node, TreeNode * parent,
        unordered_map<TreeNode *, TreeNode *> & parents) {
        if (!node)
            return ;
        parents[ node ] = parent;
        DFS_prepare_parents(node->left, node, parents);
        DFS_prepare_parents(node->right, node, parents);
    }

    TreeNode * DFS_get_starting_point (TreeNode * node, int start) {
        if (!node)
            return nullptr;
        if (node->val == start)
            return node;
        TreeNode * left = DFS_get_starting_point(node->left, start);
        if (left)
            return left;
        return DFS_get_starting_point(node->right, start);
    }
};
