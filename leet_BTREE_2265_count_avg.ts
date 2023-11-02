/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function averageOfSubtree(root: TreeNode | null): number {
    let res: number = 0

    const BFS = (node: TreeNode | null) => {
        let sum_val: number = 0
        let sum_node: number = 0
        let D: (TreeNode | null)[] = [node]
        while (D.length > 0) {
            let len: number = D.length
            let i = -1
            while (++i < len) {
                let node : TreeNode | null = D.shift()
                if (node) {
                    sum_val += node.val
                    sum_node += 1
                    if (node.left) {
                        D.push(node.left)
                    }
                    if (node.right) {
                        D.push(node.right)
                    }
                }
            }
        }

        if (Math.floor(sum_val / sum_node) === node!.val) {
            res += 1
        }
    }

    const D: (TreeNode | null)[] = [root]

    while (D.length > 0) {
        let len: number = D.length
        let i = -1
        while (++i < len) {
            let node: TreeNode | null = D.shift()
            BFS(node)
            if (node.left) {
                D.push(node.left)
            }
            if (node.right) {
                D.push(node.right)
            }
        }
    }

    return res
}
