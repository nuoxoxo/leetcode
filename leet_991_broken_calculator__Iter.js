/**
 * @param {number} startValue
 * @param {number} target
 * @return {number}
 */

var brokenCalc = function(start, target) {
    let res = 0

    while (target > start) {
        ++ res
        if (target % 2 == 0)
            target = Math.floor(target / 2)
        else
            ++ target
    }
    return res + start - target
};
