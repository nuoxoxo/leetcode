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

// Postorder (Left, Right, Root)

class Solution {
    private:
    vector<int> E;
    public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (!root)  return E ;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        E.push_back(root->val);
        return E ;
    }
};
