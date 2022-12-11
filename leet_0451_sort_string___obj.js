/**
 * @param {string} s
 * @return {string}
 */

var frequencySort = function(s) {
    let mp = {}
    let a = []
    let r = ""
    let i
    for (let c of s) {
        if (mp[c]) {
            mp[c]++
        } else {
            mp[c] = 1
        }
    }
    for (let c in mp) {
        a.push({key: c, val: mp[c]})
    }
    a.sort( (x, y) => { return y.val - x.val } )
    // console.log(a)
    i = -1
    for (let n in a) {
        // console.log(k, a[n].key, a[n].val)
        i = -1
        while (++i < a[n].val) {
            r += a[n].key
        }
    }
    return r
};
