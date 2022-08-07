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

// Inorder (Left, Root, Right)

class Solution {
    private:
    vector<int> E;
    public:
    vector<int> inorderTraversal(TreeNode* node) {
        if (!node)  return E ;
        inorderTraversal(node->left);
        E.push_back(node->val);
        inorderTraversal(node->right);
        return E ;
    }
};
