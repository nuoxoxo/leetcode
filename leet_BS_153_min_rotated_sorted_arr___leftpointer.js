/**
 * @param {number[]} nums
 * @return {number}
 */

var findMin = function(arr) {
    len = arr.length
    if (len == 1)
        return arr[0]
    if (arr[0] < arr[len - 1])
        return arr[0]
    R = len - 1
    L = 0
    while (L < R) {
        mid = Math.floor((R - L) / 2) + L
        if (arr[mid] >= arr[len - 1] && arr[mid] >= arr[0])
            L = mid + 1
        else
            R = mid
    }
    return arr[L]
};
