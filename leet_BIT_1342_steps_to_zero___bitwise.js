/**
 * @param {number} num
 * @return {number}
 */

var numberOfSteps = function(num) {
    let c = 0
    while (num != 0) {
        ++c
        if (num % 2 == 1)
            --num
        else
            num >>= 1
    }
    return c
};
