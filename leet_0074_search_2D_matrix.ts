function searchMatrix(g: number[][], target: number): boolean {
    let r = 0
    let c = g[0].length - 1
    while (r < g.length && c > -1) {
        if (g[r][c] == target)
            return true
        if (g[r][c] < target) {
            ++r
        } else {
            --c
        }
    }
    return false
};
