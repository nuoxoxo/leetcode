/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */

var backspaceCompare = function(s, t) {
    ss = foo(s)
    tt = foo(t)
    return ss == tt
}

var foo = function(word) {
    let arr = []
    for (let c of word) {
        if (c == '#') {
            if (arr.length != 0)
                arr.pop()
        } else {
            arr.push(c)
        }
    }
    let res = arr.join()
    return res
}
