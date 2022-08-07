/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */

var rotate = function(matrix) {
    let n = matrix.length, i = -1, j
    while (++i < n) {
        j = i - 1
        while (++j < n) {
            // let tmp = matrix[i][j];
            // matrix[i][j] = matrix[j][i]
            // matrix[j][i] = tmp
            [ matrix[i][j], matrix[j][i] ] = [ matrix[j][i], matrix[i][j] ]
        }
        matrix[i].reverse()
    }
};
