/**
 * @param {string} s
 * @return {string[]}
 */
var cellsInRange = function(s) {
    let r = []
    let a = [...s]
    // let a = Array.from(s)
    // let a = s.split('')
    let c1 = a[0], c2 = a[3]
    let n1 = parseInt(a[1]), n2 = parseInt(a[4])
    while (c1.charCodeAt(0) < c2.charCodeAt(0) + 1) {
        let i = n1
        while (i < n2 + 1) {
            let temp = c1 + i
            r.push(temp)
            ++i
        }
        c1 = String.fromCharCode(c1.charCodeAt(0) + 1)
    }
    return r
};
