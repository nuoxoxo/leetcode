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
 * @param {TreeNode} subRoot
 * @return {boolean}
 */

var isSubtree = function(root, sample) {
    if (!root && !sample)
        return true
    if (!root || !sample)
        return false
    if (root.val == sample.val){
        if (isSame(root, sample))
            return true
    }
    return isSubtree(root.left, sample) || isSubtree(root.right, sample)
};

function isSame(r1, r2) {
    if (!r1 && !r2)
        return true
    if (!r1 || !r2)
        return false
    if (r1.val != r2.val)
        return false
    return isSame(r1.left, r2.left) && isSame(r1.right, r2.right)
}


