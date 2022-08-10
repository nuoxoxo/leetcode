
def sorted_array_to_bst(nums)
    return make_tree(nums, 0, nums.length - 1)
end

def make_tree(nums, lend, rend) # lend:L rend:R
    if lend > rend
        return nil
    end
    mid = (rend - lend) / 2 + lend
    node = TreeNode.new(nums[mid])
    node.left = make_tree(nums, lend, mid - 1)
    node.right = make_tree(nums, mid + 1, rend)
    return node
end

# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val = 0, left = nil, right = nil)
#         @val = val
#         @left = left
#         @right = right
#     end
# end
# @param {Integer[]} nums
# @return {TreeNode}
