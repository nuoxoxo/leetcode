/**
 * @param {number[]} arr
 * @return {number}
 */
var minSetSize = function(arr) {
    E = new Object()
    for (let n of arr) {
        if (E.hasOwnProperty(n))
            E[n] += 1
        else
            E[n] = 1
    }
    // console.log(E)
    A = []
    for (let [k, v] of Object.entries(E)) {
        A.push(v)
    }
    A.sort().reverse()
    // console.log(A)
    let la = arr.length
    let count = la
    let res = 0
    for (let n of A) {
        if (count <= Math.floor(la / 2))
            return res
        count -= n
        res += 1
    }
    return res
};
