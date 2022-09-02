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
    vector<double> averageOfLevels(TreeNode* root)
    {
        vector<double>      r;
        TreeNode            *ptr;
        deque<TreeNode *>   dq;
        int                 len, i;
        long                tmp;

        dq.push_back(root);
        while ( !dq.empty())
        {
            len = dq.size();
            tmp = 0;
            i = -1;
            while (++i < len)
            {
                ptr = dq.front();
                dq.pop_front();
                tmp += ptr->val;
                if (ptr->left)
                    dq.push_back(ptr->left);
                if (ptr->right)
                    dq.push_back(ptr->right);
            }
            r.push_back((double) tmp / len);
        }
        return (print_vd(r), r);
    }

    void    print_vd(vector<double> vd)
    {
        for (double n: vd)
            cout << n << ' ';
        cout << endl;
    }
};
