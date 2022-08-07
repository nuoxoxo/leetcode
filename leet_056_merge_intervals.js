/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */

var merge = function(it) {
    let len = it.length
    let res = []
    if (len == 0)
        return res
    if (len == 1)
        return it
    // it.sort()
    it.sort( (a, b) => a[0] - b[0] )
    let temp = it[0]
    for (let n of it) {
        if (temp[1] >= n[0]) {
            temp[1] = Math.max(temp[1], n[1])
        } else {
            res.push(temp)
            temp = n
        }
    }
    res.push(temp)
    return res
};
