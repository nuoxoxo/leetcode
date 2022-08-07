/**
 * @param {string} word1
 * @param {string} word2
 * @return {number}
 */
var minDistance = function(s1, s2) {
    let n1 = s1.length
    let n2 = s2.length
    let dp = [...Array(n1 + 1)].map(e => Array(n2 + 1).fill(0))
    let i = 0
    while (++i < n1 + 1){
        let j = 0
        while (++j < n2 + 1){
            // console.log(dp[i - 1][j - 1], dp[i][j])
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]
            else
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1])
        }
    }
    return n1 + n2 - 2 * dp[n1][n2]
};
