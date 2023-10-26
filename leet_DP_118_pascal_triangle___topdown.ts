function generate( /*numRows*/ n : number): number[][] {
    let dp: number[][] = Array.from(new Array(n), () => []);
    // console.log(dp)
    dp[0] = [1]
    if (n === 1)
        return dp
    dp[1] = [1, 1]
    if (n === 2)
        return dp
    let i = 1
    while (++ i < n) {
        let j = -1
        while (++ j < i + 1) {
            if (j === 0 || j === i) {
                dp[i].push(1)
            } else {
                let temp = dp[i - 1][j - 1] + dp[i - 1][j]
                dp[i].push(temp)
            }
        }
    }
    return dp
};
