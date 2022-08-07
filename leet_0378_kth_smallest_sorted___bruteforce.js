/**
 * @param {number[][]} matrix
 * @param {number} k
 * @return {number}
 */
var kthSmallest = function(matrix, k) {
    g = []
    i = -1
    side = matrix.length
    while (++i < side) {
        j = -1
        while (++j < side)
            g.push(matrix[i][j])
    }
    g.sort((a, b) => a - b);
    return g[k - 1]
};
