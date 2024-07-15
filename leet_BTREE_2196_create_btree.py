# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def createBinaryTree(self, descriptions: List[List[int]]) -> Optional[TreeNode]:
        # description -> parent-child relation
        ischild = set()
        nodes = defaultdict(TreeNode)
        for parent, child, isleft in descriptions:
            if parent not in nodes:
                nodes[parent] = TreeNode(parent)
            if child not in nodes:
                nodes[child] = TreeNode(child)
            if isleft:
                nodes[parent].left = nodes[child]
            else:
                nodes[parent].right = nodes[child]
            ischild.add( child )
        for node, realnode in nodes.items():
            if node not in ischild:
                return realnode
        assert False


