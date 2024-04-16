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
    TreeNode* addOneRow(TreeNode* root, int val, int depth)
    {
        vector< TreeNode * (*) (TreeNode *, int, int) > Solutions {
            // DFS,
            BFS,
        };
        return Solutions[ 0 ]( root, val, depth );
    }

    // Rule
    //  for each not null node at depth, make 2 nodes of val : / \  
    //  1 - each is subtree of the old root 
    //  2 - each inherits either left or right subtree ...
    //      at either its left or its right (Important!)

    // Bottom case : depth == 1
    //  the whole tree is LEFT subtree of new root node of val

    static TreeNode * DFS( TreeNode * root, int val, int D )
    {
        if ( ! root)
            return nullptr;
        if (D == 1) // old tree is Left subtree of new root node of val
        {
            TreeNode * node = new TreeNode (val);
            node->left = root;
            return node;
        }
        if (D == 2)
        {
            TreeNode * L = new TreeNode(val);
            TreeNode * R = new TreeNode(val);
            L->left = root->left; // inherit
            R->right = root->right;
            root->left = L; // new L-R pair as subtree of old root
            root->right = R;
            return root;
        }

        // free from bottom cases
        //  - recursively getting to depth

        root->left = DFS( root->left, val, D - 1 );
        root->right = DFS( root->right, val, D - 1 );

        return root;

    }

    static TreeNode * BFS( TreeNode * root, int val, int D )
    {
        assert(root);
        if (D == 1)
        {
            TreeNode * node = new TreeNode (val);
            node->left = root;
            return node;
        }
        deque<TreeNode *> Q {root};
        while ( ! Q.empty())
        {
            D--;
            if ( ! D)
            {
                return root;
            }
            TreeNode *L, *R;
            int i = Q.size();
            while (--i > -1)
            {
                TreeNode * node = Q.front();
                Q.pop_front();

                if (D == 1)
                {
                    L = new TreeNode(val);
                    R = new TreeNode(val);
                    L->left = node->left; // inherit
                    R->right = node->right;
                    node->left = L; // new L-R pair as subtree of old root
                    node->right = R;
                }
                else
                {
                    if (node->left)
                    {
                        Q.push_back(node->left);
                    }
                    if (node->right)
                    {
                        Q.push_back(node->right);
                    }
                }
            }
        }
        return root;
    }

};
