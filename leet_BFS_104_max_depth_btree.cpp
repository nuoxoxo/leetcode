/// BFS

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        if (!root)
            return (0) ;

        deque<TreeNode*>    E = { root };
        int                 depth = 0;

        while (!E.empty())
        {
            int i = -1, len = E.size() ;
            while (++i < len)
            {
                TreeNode*   temp = E.front() ;

                E.pop_front() ;
                if (temp->left)
                    E.push_back(temp->left) ;
                if (temp->right)
                    E.push_back(temp->right);
            }
            ++ depth ;
        }
        return depth ;
    }
};
