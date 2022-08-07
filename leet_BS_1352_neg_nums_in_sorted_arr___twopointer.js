/**
 * @param {number[][]} grid
 * @return {number}
 */
var countNegatives = function(grid) {
    let i = 0
    let r = grid.length
    let c = grid[0].length
    let j = c - 1
    let res = 0
    while (i < r && j > -1) {
        if (grid[i][j] < 0) {
            res += r - i
            j -= 1
        } else {
            i += 1
        }
    }
    return res
};
