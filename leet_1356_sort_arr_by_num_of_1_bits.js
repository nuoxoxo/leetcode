/**
 * @param {number[]} arr
 * @return {number[]}
 */

var sortByBits = function(arr) {
    arr.sort((a, b) => {
        let x = onebits(a)
        let y = onebits(b)
        if (x == y) return a - b
        return x - y
    })
    return arr
};

var onebits = function(n) {
    let c = 0
    while (n != 0) {
        c += n & 1
        n = n >> 1
    }
    return c
}
