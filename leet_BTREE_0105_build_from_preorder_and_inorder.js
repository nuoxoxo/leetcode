
var buildTree = function(preorder, inorder) {
    if (preorder.length == 0 || inorder.length == 0)
        return null
    let head = preorder[0]
    let node = new TreeNode(head)
    let mid = inorder.indexOf(head)
    let po1 = preorder.slice(1, mid + 1)
    let io1 = inorder.slice(0, mid + 1)
    node.left = buildTree(po1, io1)
    let po2 = preorder.slice(mid + 1)
    let io2 = inorder.slice(mid + 1)
    node.right = buildTree(po2, io2)
    return node
};

/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
