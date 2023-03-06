/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */

var findKthPositive = function(arr, k) {
    if (k < arr[0])
        return k    // case 1 : nothing left to count, yield k
    k = k - arr[0] + 1 // case 2 : if we can count, start at (k - [i] + 1)
    let i = 0
    while (++i < arr.length) {
        let diff = arr[i] - arr[i - 1]
        if (diff == 1)
            continue
        if (k < diff)
            break
        k -= diff - 1
    }
    return arr[i - 1] + k
};
