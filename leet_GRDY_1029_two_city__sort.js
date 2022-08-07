/**
 * @param {number[][]} costs
 * @return {number}
 */

// function cmp(x, y) {
//     return x[0] - x[1] < y[0] - y[1]
// }

var twoCitySchedCost = function(c)
{
    let half = Math.floor(c.length / 2)
    let res = 0
    let i = -1
    c.sort((x, y) => x[0] - x[1] - (y[0] - y[1]))
    while (++ i < half) {
        res += c[i][0] + c[i + half][1]
    }
    return res 
};
