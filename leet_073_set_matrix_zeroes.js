/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

var setZeroes = function(matrix) {
    let c = matrix[0].length
    let r = matrix.length
    let x = []
    let y = []
    let i = -1, j
    while (++i < r) {
        j = -1
        while (++j < c) {
            if (matrix[i][j] == 0) {
                x.push(i)
                y.push(j)
            }
        }
    }
    i = -1
    while (++i < x.length) {
        j = -1
        while (++j < c) matrix[ x[i] ][ j ] = 0
        j = -1
        while (++j < r) matrix[ j ][ y[i] ] = 0
    }
};
