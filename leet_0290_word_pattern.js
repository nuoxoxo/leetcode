/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */

var wordPattern = function(pattern, s) {
    let len = pattern.length
    if (len != (s.match(/ /g) || []).length + 1)
        return false
    let words = s.split(' ')
    let wmap = new Object()
    let pmap = new Object()
    i = -1
    while (++ i < len) {
        p = pattern[i]
        w = words[i]
        if (!(pmap.hasOwnProperty(p)) && !(wmap.hasOwnProperty(w))) {
            pmap[p] = w
            wmap[w] = p
        } else if (pmap.hasOwnProperty(p) && pmap[p] != w) {
            return false
        } else if (wmap.hasOwnProperty(w) && wmap[w] != p) {
            return false
        }
    }
    return true
};
