function largestLocal(g: number[][]): number[][] {
    let R: number = g.length - 2
    let C: number = g[0].length - 2

    //  Does not work

    // let res: number[][] = new Array(R).fill(Array(C, 0))
    // let res: number[][] = new Array(R).fill(Array(C).fill(0))


    //  Correct way to fill a 2-D array

    // let res: number[][] = Array.from({ length: R }, () => Array(C).fill(0))
    let res: number[][] = Array(R).fill(0).map(() => Array(C).fill(0));

    let r: number = -1, c: number
    while (++r < R) {
        c = -1
        while (++c < C) {
            res[r][c] = Max_Local(g, r, c)
        }
    }
    return res
};

// helper

function Max_Local(g: number[][], r: number, c: number) {
    let res: number = -1
    let rr: number = r - 1
    let cc: number
    while (++rr < r + 3) {
        cc = c - 1
        while (++cc < c + 3) {
            let val = g[rr][cc]
            res = res > val ? res : val
        }
    }
    return res
}
