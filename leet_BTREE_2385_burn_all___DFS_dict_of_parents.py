# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def amountOfTime(self, root: Optional[TreeNode], start: int) -> int:
        def DFS_find_start (node, start: int):#, start_node: TreeNode):
            if not node:
                # done search if starting node has been found
                return None
            if node.val == start:
                return node
            left = DFS_find_start( node.left, start )
            if left: 
                return left
            return DFS_find_start( node.right, start )

        def DFS_prepare_parents (node, parent: TreeNode, parents: Dict[TreeNode, TreeNode]):
            if not node:
                return
            parents[node] = parent
            DFS_prepare_parents ( node.left, node, parents)
            DFS_prepare_parents ( node.right, node, parents )

        def DFS_max_dist_from (node, parents: Dict[TreeNode, TreeNode], seen: Set[int]):
            if not node or node in seen:
                return 0
            seen.add( node )
            furthest = max( DFS_max_dist_from(node.left, parents, seen),\
                            DFS_max_dist_from(node.right, parents, seen),\
                            DFS_max_dist_from(parents[node], parents, seen) )
            return furthest + 1

        # step 1/3 : find out where we start
        snode = DFS_find_start(root, start)

        # step 2/3 : we need to include '.parent' attribute in a TreeNode
        # to do this in python is simple - just add .parent to each node 
        # alt. way :
        # here we use a dict instead of modifying the node struct
        parents = defaultdict(TreeNode)
        DFS_prepare_parents (root, None, parents)

        # step 3/3 : visualize the original problem
        # TimeToCoverAll is in fact the dist btw [ here, furthest node ]
        return DFS_max_dist_from(snode, parents, set()) - 1

