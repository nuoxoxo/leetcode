function checkStraightLine(c: number[][]): boolean {
    let n: number = c.length
    if (n == 2) {
        return true
    }
    let dx: number = c[1][0] - c[0][0]
    let dy: number = c[1][1] - c[0][1]
    let slope: number = dx ? dy / dx : -1
    let i: number = 1
    while (++i < n) {
        dx = c[i][0] - c[i - 1][0]
        dy = c[i][1] - c[i - 1][1]

        let temp_slope: number = dx ? dy / dx : -1
        if (temp_slope != slope) {
            return false
        }
    }
    return true
};
