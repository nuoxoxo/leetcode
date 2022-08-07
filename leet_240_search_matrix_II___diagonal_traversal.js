/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */

var searchMatrix = function(matrix, target) {
    let j = matrix[0].length - 1
    let r = matrix.length
    let i = 0
    while (i < r && j > -1){
        let val = matrix[i][j]
        if (target == val)
            return true
        else if (target > val)
            ++ i
        else
            -- j
    }
    return false
};
