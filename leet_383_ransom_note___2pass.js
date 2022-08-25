/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function(ransomNote, magazine) {
    let mp = new Array(26).fill(0)
    let a = 'a'.charCodeAt(0)
    let i
    for (let c of magazine) {
        mp[c.charCodeAt(0) - a]++
    }
    for (let c of ransomNote) {
        i = c.charCodeAt(0) - a
        mp[i]--
        if (mp[i] < 0)
            return false
    }
    return true
};
