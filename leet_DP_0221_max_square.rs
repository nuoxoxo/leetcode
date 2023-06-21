impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        if matrix.is_empty() {
            return 0;
        }
        
        let r = matrix.len();
        let c = matrix[0].len();
        let mut dp: Vec<Vec<i32>> = vec![vec![0; c + 1]; r + 1];
        let mut a = 0;
        
        for i in 0 .. r {
            for j in 0 .. c {
                if matrix[i][j] == '1' {
                    let n = dp[i][j].min(dp[i + 1][j]).min(dp[i][j + 1]) + 1;
                    dp[i + 1][j + 1] = n;
                    a = a.max(n);
                }
            }
        }
        a * a
    }
}
