/**
 * @param {number[][]} firstList
 * @param {number[][]} secondList
 * @return {number[][]}
 */
var intervalIntersection = function(first, second) {
    let res = []
    let i = 0
    let j = 0
    let hi, lo
    while (i < first.length && j < second.length) {
        let f = first[i]
        let s = second[j]
        lo = f[0] > s[0] ? f[0] : s[0]
        hi = f[1] < s[1] ? f[1] : s[1]
        if (lo <= hi)
            res.push( [ lo, hi ] )
        if (f[1] < s[1])
            ++i
        else
            ++j
    }
    return res 
};
