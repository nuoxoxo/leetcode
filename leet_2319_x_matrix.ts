function checkXMatrix(grid: number[][]): boolean {
    let side = grid.length
    let r: number = -1, c: number
    while (++r < side) {
        c = -1
        while (++c < side) {
            if (c == r || c == side - r - 1) {
                if ( !grid[r][c]) {
                    return false
                }
            } else {
                if (grid[r][c]) {
                    return false
                }
            }
        }
    }
    return true
};
