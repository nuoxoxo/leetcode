/**
 * @param {number[][]} matrix
 * @return {number[]}
 */

var spiralOrder = function(matrix) {
    let hicol = matrix[0].length
    let hirow = matrix.length
    let area = hicol * hirow
    if (area == 1)
        return matrix[0]
    let locol, lorow, count, r, c
    locol = lorow = -1
    r = c = count = 0
    let res = []
    while (true) {
        if (count != 0)
            ++c
        while (c < hicol) {
            res.push(matrix[r][c])
            ++count
            ++c
        }
        if (count == area)
            break
        --c
        ++r
        while (r < hirow) {
            res.push(matrix[r][c])
            ++count
            ++r
        }
        if (count == area)
            break
        --r
        while (--c > locol) {
            res.push(matrix[r][c])
            ++count
        }
        if (count == area)
            break
        ++c
        --hirow
        --hicol
        ++lorow
        ++locol
        while (--r > lorow) {
            res.push(matrix[r][c])
            ++count
        }
        if (count == area)
            break
        ++r
    }
    return res
};
