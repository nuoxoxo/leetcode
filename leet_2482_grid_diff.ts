function onesMinusZeros(grid: number[][]): number[][] {
    let rows:number = grid.length
    let cols:number = grid[0].length
    let r:number, c:number
    let r1:number[] = [], r0:number[] = []
    let c1:number[] = new Array(cols).fill(0)
    let c0:number[] = new Array(cols).fill(0)
    // let res:number[][] = new Array(rows).fill(new Array(cols).fill(0))
    // 👆 : Wrong
    let res:number[][] = new Array(rows).fill(null).map(
        () => new Array(cols).fill(0)
    )
    for (let row of grid) {
        r1.push(row.filter(x => x == 1).length)
        r0.push(row.filter(x => x == 0).length)
        r = -1
        while (++r < cols) {
            if (row[r] == 0) {
                ++c0[r]
            } else {
                ++c1[r]
            }
        }
    }
    console.log(r1, r0, c1, c0)
    r = -1
    while (++r < rows) {
        c = -1
        while (++c < cols) {
            res[r][c] = r1[r] - r0[r] + c1[c] - c0[c]
        }
    }
    return res
};
