/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(arr) {
    L = 0
    R = arr.length - 1
    while (L <= R) {
        mid = Math.floor((R - L + 1) / 2) + L
        if (arr[mid] < arr[mid + 1])
            L = mid + 1
        else
            R = mid - 1
    }
    return L
};
