function maximalSquare(m: string[][]): number {
    if (m.length < 1) {
        return 0
    }
    let R:number = m.length
    let C:number = m[0].length
    let DP:number[][] = new Array(R + 1).fill(null).map(() => new Array(C + 1).fill(0))
    let a:number = 0
    let r:number = -1, c:number, n:number
    while (++r < R) {
        c = -1
        while (++c < C) {
            if (m[r][c] == '1') {
                n = 
    Math.min(DP[r][c], DP[r + 1][c], DP[r][c + 1]) + 1
                DP[r + 1][c + 1] = n
                a = Math.max(a, n)
            }
        }
    }
    return a * a
};
