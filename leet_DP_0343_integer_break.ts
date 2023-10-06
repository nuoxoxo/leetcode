function integerBreak(n: number): number {
    if (n < 4) {
      return n - 1;
    }
    const dp: number[] = Array(n + 1).fill(0);
    dp[2] = 1 * 1;
    let i = 2
    while (++i < n + 1) {
        let j = 0
        while (++j < Math.floor(i / 2) + 1) {
            dp[i] = Math.max(dp[i], dp[i - j] * j, (i - j) * j);
      }
    }
    return dp[n];
};
