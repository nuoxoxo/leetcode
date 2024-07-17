# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        return [
            DFS_make_tree,
            # DFS_del_node,
        ][0](root, to_delete)
        
def DFS_make_tree(root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
    res = []
    def FillForest (node: Optional[TreeNode], hasParent: bool) -> None:
        if not node:
            return
        validNewParent = True
        if node.val in to_delete:
            validNewParent = False
        if validNewParent and not hasParent:
            res.append(node)
        FillForest(node.left, validNewParent)
        FillForest(node.right, validNewParent)
        if node.left and node.left.val in to_delete:
            node.left = None
        if node.right and node.right.val in to_delete:
            node.right = None
    FillForest(root, False)
    return res

def DFS_del_node(root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
    res = []
    def DFS(node: Optional[TreeNode], hasParent: bool) -> TreeNode:
        if not node:
            return None
        new_parent = node
        if node.val in to_delete:
            new_parent = None
        if new_parent and not hasParent:
            res.append(new_parent)
        node.left = DFS(node.left, new_parent != None)
        node.right = DFS(node.right, new_parent != None)
        return new_parent
    DFS(root, False)
    return res
