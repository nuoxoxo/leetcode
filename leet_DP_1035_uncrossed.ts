function maxUncrossedLines(n1: number[], n2: number[]): number {
    
    // way 2: try using 1-d array   /* Not Workking */
    
    /*
    let len1 = n1.length
    let len2 = n2.length
    let dp = [...new Array(len2 + 1)].fill(0)
    let i = -1, j
    while (++i < len1) {
        let prev = 0
        j = -1
        while (++j < len2) {
            if (n1[i] == n2[j]) {
                prev = (dp[j], dp[j + 1], prev + 1)
            } else {
                prev = (dp[j], dp[j + 1], prev)
            }
            prev = dp[j + 1]
        }
    }
    return dp[len2 - 1]
    */
    
    
    // way 1: 2d array
    
    let len1: number = n1.length
    let len2: number = n2.length
    let dp: number[][] = [...new Array(len1 + 1)].map(() => new Array(len2 + 1).fill(0))
    let i = -1, j
    while (++i < len1) {
        j = -1
        while (++j < len2) {
            let prev: number
            if (n1[i] == n2[j]) {
                prev = dp[i][j] + 1
            } else {
                prev = Math.max(dp[i + 1][j], dp[i][j + 1])
            }
            dp[i + 1][j + 1] = prev
        }
    }
    console.log(dp)
    return dp[len1][len2]
};
