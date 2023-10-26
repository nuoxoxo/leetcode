function minCostClimbingStairs(cost: number[]): number {
    let size:number = cost.length
    let dp:number[] = Array(size + 1).fill(0)
    let i = 1
    while (++i < size + 1) {
        let l = dp[i - 2] + cost[i - 2]
        let r = dp[i - 1] + cost[i - 1]
        dp[i] = l < r ? l : r
    }
    return dp[size]
};
