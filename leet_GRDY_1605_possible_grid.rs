impl Solution {
    pub fn restore_matrix(row_sum: Vec<i32>, col_sum: Vec<i32>) -> Vec<Vec<i32>>
    {
        let mut rs = row_sum;
        let mut cs = col_sum;
        let R = rs.len();
        let C = cs.len();
        let mut res = vec![vec![0; C]; R];
        let mut r = 0;
        let mut c = 0;
        while r < R && c < C
        {
            res[r][c] = rs[r].min(cs[c]);
            rs[r] -= res[r][c];
            cs[c] -= res[r][c];
            while r < R && rs[r] == 0
            {
                r += 1;
            }
            while c < C && cs[c] == 0
            {
                c += 1;
            }
        }
        res
    }
}
