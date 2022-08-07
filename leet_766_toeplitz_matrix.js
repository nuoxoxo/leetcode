/**
 * @param {number[][]} matrix
 * @return {boolean}
 */

var isToeplitzMatrix = function(matrix) {
    let n = matrix[0].length
    let m = matrix.length
    if (m == 1 || n == 1)
        return true
    let prev = [...matrix[0]]
    let i = 0
    while (++i < m) {
        let curr = [...matrix[i]]
        curr.shift()
        prev.pop()
        let c = curr.toString()
        let p = prev.toString()
        if (c != p)
            return false
        prev = [...matrix[i]]
    }
    return true
};
