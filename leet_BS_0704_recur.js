/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

var search = function(a, target) {
    n = a.length
    if (n == 1) {
        if (a[0] == target)
            return 0
        else
            return -1
    }
    L = n - 1
    R = 0
    return bs(a, target, 0, L)
        
};

function bs(a, target, L, R) {
    if (L > R)  return -1
    mid = Math.floor((L + R) / 2)
    if (a[mid] == target)
        return mid
    else if (a[mid] < target)
        return bs(a, target, mid + 1, R)
    return bs(a, target, L, mid - 1)
}
