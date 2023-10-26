impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let size = cost.len();
        let mut dp = vec![0; size + 1];
        for i in 2..size + 1 {
            let l = dp[i - 2] + cost[i - 2];
            let r = dp[i - 1] + cost[i - 1];
            dp[i] = l.min(r);
        }
        dp[size]
    }
}
