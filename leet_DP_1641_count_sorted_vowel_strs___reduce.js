/**
 * @param {number} n
 * @return {number}
 */
var countVowelStrings = function(n) {
    let dp = new Array(5)
    dp.fill(1)
    while (--n) {
        let i = 4
        while (--i > -1)
            dp[i] += dp[i + 1]
    }
    return dp.reduce((a, b) => a + b, 0)
};
