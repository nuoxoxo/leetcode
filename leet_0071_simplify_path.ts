/**
 * @param {string} path
 * @return {string}
 */

var simplifyPath = function(path) {
    let res = '/'
    let arr = []
    let temp = path.split('/').filter((e) => {return e != ''})
    for (let word of temp) {
        if (word == '..') {
            if (arr.length) {
                arr.pop()
            }
        } else if (word != '.') {
            arr.push(word)
        }
    }
    while (arr.length) {
        res += arr.shift()
        if (arr.length)
            res += '/'
    }
    return res
};
