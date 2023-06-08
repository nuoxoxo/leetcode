function countNegatives(g: number[][]): number {
    let R: number = g.length
    let C: number = g[0].length
    let r: number = 0
    let c: number = C - 1
    let res: number = 0
    while (r < R && c > -1) {
        if (g[r][c] < 0) {
            res += R - r
            --c
        } else {
            ++r
        }
    }
    return res
};
