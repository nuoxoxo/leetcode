/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nuo *** */

class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high)
    {
        int N = 0;

        helper(N, root, low, high);

        return (N);
    }
    
    void    helper(int& N, TreeNode* p, int low, int high)
    {
        if (!p)     return ;
        if (p->val <= high && p->val >= low)    N += p->val;
        helper(N, p->right, low, high);
        helper(N, p->left, low, high);
    }
};
