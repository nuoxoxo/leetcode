/**
 * @param {number[][]} points
 * @param {number} k
 * @return {number[][]}
 */
var kClosest = function(points, k) {
    let res = []
    let arr = []
    let i = -1
    while (++i < points.length) {
        p = points[i]
        arr.push([p[0] * p[0] + p[1] * p[1], p[0], p[1]])
    }
    arr.sort((a, b) => a[0] - b[0])
    while (--k != -1) {
        temp = arr.shift()
        res.push([temp[1], temp[2]])
    }
    return res
};
