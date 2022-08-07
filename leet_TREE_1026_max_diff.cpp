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
    int maxAncestorDiff(TreeNode* root) {
        return find_max(root, -1 * 1e9, 1e9);
    }

    int find_max(TreeNode* root, int max, int min)
    {
        if (!root)  return (max - min);
        max = max > root->val ? max : root->val;
        min = min < root->val ? min : root->val;
        return (std::max(find_max(root->left, max, min), find_max(root->right, max, min)));
    }
};
