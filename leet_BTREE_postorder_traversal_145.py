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

# Postorder (Left, Right, Root)

class Solution:
    def pt(self, node, E):
        if node is not None:
            self.pt(node.left, E)
            self.pt(node.right, E)
            E.append(node.val)
            
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        E = []
        self.pt(root, E)
        return E
