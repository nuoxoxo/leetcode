/**
 * @param {number[][]} triangle
 * @return {number}
 */

var minimumTotal = function(tg) {
    let i = tg.length - 1
    while (--i > -1) {
        let j = -1
        while (++j < tg[i].length) 
            tg[i][j] += Math.min(tg[i + 1][j], tg[i + 1][j + 1])
    }
    return tg[0][0]
};
