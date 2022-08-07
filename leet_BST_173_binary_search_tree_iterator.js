/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 */

var BSTIterator = function(root) {
    this.it = 0
    let temp = []
    function inorder_traversal(node) {
        if (!node)
            return
        inorder_traversal(node.left)
        temp.push(node.val)
        inorder_traversal(node.right)
    }
    inorder_traversal(root)
    this.arr = [...temp]
};

/**
 * @return {number}
 */

BSTIterator.prototype.next = function() {
    let n = this.arr.length
    let val
    if (this.it < n) {
        val = this.arr[this.it]
    } else {
        val = this.arr[n - 1]
    }
    this.it += 1
    return val
};

/**
 * @return {boolean}
 */

BSTIterator.prototype.hasNext = function() {
    return this.it < this.arr.length
};

/** 
 * Your BSTIterator object will be instantiated and called as such:
 * var obj = new BSTIterator(root)
 * var param_1 = obj.next()
 * var param_2 = obj.hasNext()
 */
