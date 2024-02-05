function change(amount: number, coins: number[]): number {

    let sum = 0
    //   coins.forEach(n=>{sum+=n})
    //   if (amount < sum) return 0
    let M = amount
    let C = coins.length
    let dp = new Array(M + 1).fill(0).map(() => new Array(C + 1).fill(0))
    dp[0].fill(1)
    //console.log(dp)
    let m = 0
    while (++m < M + 1) {
        let j = C
        while (--j > -1) {
            dp[m][j] = dp[m][j + 1]
            if (m - coins[j] > -1) {
                dp[m][j] += dp[m - coins[j]][j]
            }
        }
    }
    return dp[M][0]
};
