/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var search = function(arr, target) {
    n = arr.length
    if (n == 1){
        if (arr[0] == target)
            return 0
        else
            return -1
    }
    R = n - 1
    L = 0
    while (L <= R){
        mid = Math.floor((L + R) / 2)
        if (arr[mid] == target)
            return mid
        else if (arr[mid] > target)
            R = mid - 1
        else
            L = mid + 1
    }
    return -1
};
