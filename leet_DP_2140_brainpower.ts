function mostPoints(questions: number[][]): number {
    let len = questions.length
    let dp = Array(len + 1).fill(0)
    // console.log(dp)
    let i = len
    while (--i > -1) {
        let pts = questions[i][0]
        let pow = questions[i][1]
        let nextpos = i + pow + 1
        if (nextpos > len) {
            nextpos = len
        }
        dp[i] = Math.max(
            pts + dp[nextpos], 
            dp[i + 1]
        )
    }
    console.log(dp)
    return dp[0]
};
