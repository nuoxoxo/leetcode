/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {number}
 */

var numSubmatrixSumTarget = function(matrix, target) {
    let r = matrix.length
    if (r == 0)
        return r
    let c = matrix[0].length
    let count = 0
    let i = -1, j, k
    while (++i < r) {
        let temp = Array(c).fill(0)
        j = i + 1
        while (--j > -1) {
            k = -1
            while (++k < c)
                temp[k] += matrix[j][k]
            count += subarray_sum(temp, target)
        }
    }
    return count
};

function subarray_sum(arr, tar) {
    let o = new Object()
    let size = arr.length
    let res = 0
    let tt = 0
    let i = -1

    while (++i < size) {
        tt += arr[i];
        if (tt == tar)
            res++
        if (o.hasOwnProperty(tt - tar))
            res += o[tt - tar]
        if (o.hasOwnProperty(tt))
            o[tt]++
        else
            o[tt] = 1
    }
    return res
}
