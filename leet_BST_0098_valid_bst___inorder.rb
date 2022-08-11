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
# @return {Boolean}

def is_valid_bst(root)
    nums = []
    inorder(root, nums)
    1.upto(nums.length - 1) do |index|
        if nums[index - 1] >= nums[index]
            return false
        end
    end
    true
end

def inorder(node, nums)
    return if node.nil?
    inorder(node.left, nums)
    nums.push(node.val)
    inorder(node.right, nums)
end
