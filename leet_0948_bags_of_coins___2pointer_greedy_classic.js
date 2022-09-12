/**
 * @param {number[]} tokens
 * @param {number} power
 * @return {number}
 */
var bagOfTokensScore = function(tokens, power) {
    tokens.sort((a, b) => a - b)
    i = 0
    j = tokens.length - 1
    res = cur = 0
    while (i <= j)
    {
        if (tokens[i] <= power) {
            cur += 1
            if (res < cur) {
                res = cur
            }
            power -= tokens[i]
            i++
        } else if (cur > 0) {
            cur -= 1
            power += tokens[j]
            j -= 1
        } else {
            break
        }
    }
    return res
};
