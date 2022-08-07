/**
 * @param {number[]} digits
 * @return {number[]}
 */

var plusOne = function(digits) {
    let i = digits.length
    while (--i > -1){
        if (digits[i] == 9){
            digits[i] = 0
        } else {
            digits[i] += 1
            return digits
        }
    }
    digits.unshift(1)
    return digits
};
