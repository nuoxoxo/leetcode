/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

var setZeroes = function(matrix) {
    let r = matrix.length
    let c = matrix[0].length
    let R = new Array(r).fill(1)
    let C = new Array(c).fill(1)
    let i = -1, j
    while (++i < r) {
        j = -1
        while (++j < c)
            if (matrix[i][j] === 0)
                R[i] = 0, C[j] = 0
    }
    i = -1
    while (++i < r) {
        j = -1
        while (++j < c)
            if (R[i] === 0 || C[j] === 0)
                matrix[i][j] = 0
    }
};
