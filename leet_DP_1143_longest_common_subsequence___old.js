/**
 * @param {string} text1
 * @param {string} text2
 * @return {number}
 */

var longestCommonSubsequence = function(a, b)
{
    let n1 = a.length
    let n2 = b.length
    let dp = [...Array(n1 + 1)].map(e => Array(n2 + 1).fill(0))
    let i = 0
    while (++i < n1 + 1) {
        j = 0
        while (++j < n2 + 1) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1
            else
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
        }
    }
    return dp[n1][n2]
};
