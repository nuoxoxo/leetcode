/**
 * @param {number[]} arr
 * @return {number}
 */

var findLengthOfShortestSubarray = function(arr) {
    n = arr.length
    if (n == 0 || n == 1)
        return 0
    R = n - 1
    while (R > 0 && arr[R - 1] <= arr[R])
        --R
    res = R
    L = -1
    while (++L < n) {
        if (L >= R || (L > 0 && arr[L - 1] > arr[L]))
            break
        while (R < n && arr[L] > arr[R])
            R += 1
        res = Math.min(R - L - 1, res)
    }
    return res
};
