/**
 * @param {number} rowIndex
 * @return {number[]}
 */

var getRow = function(r) {
    if (r == 0)
        return [1]
    if (r == 1)
        return [1, 1]
    let p = Array.from(new Array(r + 1), () => [])
    console.log(p)
    p[0] = [1]
    p[1] = [1, 1]
    let i = 1
    while (++ i < r + 1) {
        let j = -1
        while (++ j < i + 1) {
            if (j == 0 || j == i)
                p[i].push(1)
            else
                p[i].push(p[i - 1][j - 1] + p[i - 1][j])
        }
    }
    return p[r]
};
