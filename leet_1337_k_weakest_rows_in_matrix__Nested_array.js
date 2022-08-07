/**
 * @param {number[][]} mat
 * @param {number} k
 * @return {number[]}
 */

var kWeakestRows = function(mat, k) {
    let n = mat.length
    let res = []
    let arr = []
    let i = -1
    while (++ i < n) {
        let tmp = mat[i].reduce((total, a) => total + a, 0)
        arr.push([i, tmp])
    }
    arr.sort((a, b) => a[1] - b[1])
    console.log(arr)
    i = -1
    while (++ i < k)
        res.push(arr[i][0])
    return res
};
