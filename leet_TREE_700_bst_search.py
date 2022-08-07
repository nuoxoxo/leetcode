#* ************************************************************************** *#
#*                                                                            *#
#*                            \\             #`#``                            *#
#*                            ~\o o_       0 0\                               *#
#*                            # \__)      (u  ); _  _                         *#
#*                     # \# \#  #           \  \# \# \                        *#
#*                    #(   . . )            (         )\                      *#
#*                   #  \_____#              \_______#  \                     *#
#*                       []  []               [[] [[]    *.                   *#
#*                       []] []]              [[] [[]                         *#
#*                                                                            *#
#* ****************************************************************** .py *** *#

class Solution:
    def searchBST(self, node: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not node:
            return None
        if node.val == val:
            return node
        if val > node.val:
            return self.searchBST(node.right, val)
        else:
            return self.searchBST(node.left, val)
