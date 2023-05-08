impl Solution {
    pub fn check_x_matrix(grid: Vec<Vec<i32>>) -> bool {
        let mut len = grid.len();
        for r in 0 .. len {
            for c in 0 .. len {
                if c == r || c == len - r - 1 {
                    if grid[r][c] == 0 {
                        return false;
                    }
                } else {
                    if grid[r][c] != 0 {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}
