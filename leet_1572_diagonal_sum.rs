impl Solution {
    pub fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
        let (mut res, len) = (0, mat.len());
        for i in 0 .. len {
            res += mat[i][i] + mat[i][len - i - 1];
        }
        if len % 2 == 1 {
            res -= mat[len / 2][len / 2]
        }
        return res;

    }
}
