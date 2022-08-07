#* ******************************************** *#
#*                                              *#
#*              \\             /`/``            *#
#*              ~\o o_       0 0\               *#
#*              / \__)      (u  ); _  _         *#
#*       / \/ \/  /           \  \/ \/ \        *#
#*      /(   . . )            (         )\      *#
#*     /  \_____/              \_______/  \     *#
#*         []  []               [[] [[]    *.   *#
#*         []] []]              [[] [[]         *#
#*                                              *#
#* ************************************ nuo *** *#

# Inorder (Left, Root, Right)

class Solution:
    def it(self, node, E):
        if node is not None:
            self.it(node.left, E)
            E.append(node.val)
            self.it(node.right, E)
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        E = []
        self.it(root, E)
        return E
