# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {TreeNode} root
# @return {TreeNode}

def prune_tree(node)
    return node if node == nil
    node.left = prune_tree(node.left)
    node.right = prune_tree(node.right)
    return nil if node.left == nil && node.right == nil && node.val == 0
    return node
end
