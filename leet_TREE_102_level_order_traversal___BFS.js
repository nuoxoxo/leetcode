

var levelOrder = function(root) {
    let bfs = []
    let res = []
    if (!root)
        return []
    bfs.push(root)
    while (bfs.length) {
        let size = bfs.length
        let temp = []
        while (size --) {
            let node = bfs[0]
            bfs.shift()
            if (node.left) {
                bfs.push(node.left)
            }
            if (node.right) {
                bfs.push(node.right)
            }
            temp.push(node.val)
        }
        res.push(temp)
    }
    return res
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
 * @param {TreeNode} root
 * @return {number[][]}
 */
