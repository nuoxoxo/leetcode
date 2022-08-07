/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    matrix.forEach( (r, i, arr) => r.forEach( (c, j) => {
        if (j > i - 1) {
            [ arr[i][j], arr[j][i] ] = [ arr[j][i], arr[i][j] ]
        }
    }))
    matrix.forEach( r => r.reverse() )
};
