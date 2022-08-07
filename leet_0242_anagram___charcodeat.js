/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
    if (s.length == t.length) {
        let arr = new Array(26).fill(0)
        let a = "a".charCodeAt(0)
        let i = -1
        while (++i < s.length) {
            arr[s.charCodeAt(i) - a]++
            arr[t.charCodeAt(i) - a]--
        }
        for (let n of arr) {
            if (n != 0)
                return false
        }
        return true
    }
    return false
};
