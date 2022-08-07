/* ******************************************** */
/*                                              */
/*              \\             /`/``            */
/*              ~\o o_       0 0\               */
/*              / \__)      (u  ); _  _         */
/*       / \/ \/  /           \  \/ \/ \        */
/*      /(   . . )            (         )\      */
/*     /  \_____/              \_______/  \     */
/*         []  []               [[] [[]    *.   */
/*         []] []]              [[] [[]         */
/*                                              */
/* ************************************ nuo *** */

// Preorder (Root, Left, Right)

class Solution {
    private:
    vector<int> E;
    public:
    vector<int> preorderTraversal(TreeNode* node)
    {
        if (!node)  return E ;
        E.push_back(node->val);
        preorderTraversal(node->left);
        preorderTraversal(node->right);
        return E ;
    }
};
