/**
 * @param {string[]} strs
 * @return {string[][]}
 */

var groupAnagrams = function(strs) {
    let obj = new Object()
    let res = []
    for (let s of strs) {
        let temp = s.split('').sort().join('')
        if (obj.hasOwnProperty(temp))
            obj[temp].push(s)
        else
            obj[temp] = [s]
    }
    for (let [key, val] of Object.entries(obj)) {
        res.push(val)
    }
    return res
};
