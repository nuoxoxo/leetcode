/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */

var sortColors = function(n) {
    let s = n.length
    if (s < 2)
        return
    if (s == 2) {
        if (n[0] > n[1])
            [n[0], n[[1]]] = [n[1], n[0]]
        return
    }
    let i = 0, j = s - 1, k
    while (n[i] == 0)
        ++ i
    while (n[j] == 2)
        -- j
    k = i - 1
    while ( ++ k <= j) {
        if (n[k] == 0) {
            n[k] = n[i]
            n[i ++ ] = 0
        }
        else if (n[k] == 2) {
            n[k] = n[j]
            n[j -- ] = 2
            -- k
        }
    }
};
