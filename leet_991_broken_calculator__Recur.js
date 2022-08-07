/**
 * @param {number} startValue
 * @param {number} target
 * @return {number}
 */
var brokenCalc = function(start, target) {
    if (start >= target)
        return start - target
    if (target % 2 == 0)
        return 1 + brokenCalc(start, Math.floor(target / 2))
    return 1 + brokenCalc(start, target + 1)
};
