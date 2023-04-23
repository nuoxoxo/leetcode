/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

var searchMatrix = function(matrix, target) {
    let i = 0
    let j = matrix[0].length - 1
    while (i < matrix.length && j > -1) {
        let tmp = matrix[i][j]
        if (tmp == target)
            return true
        if (tmp > target)
            --j
        if (tmp < target)
            ++i
    }
    return false
};
