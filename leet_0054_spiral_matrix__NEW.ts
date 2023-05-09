function spiralOrder(g: number[][]): number[] {
    let res: number[] = []
    let rows = g.length
    let cols = g[0].length
    let U = 0, L = 0
    let D = rows - 1, R = cols - 1 //, D
    let i: number;
    while (U <= D && L <= R) {
        console.log(U,D,L,R)
        i = L
        while (i <= R) {
            res.push(g[U][i])
            ++i
        }
        U++
        i = U
        while (i <= D) {
            res.push(g[i][R])
            ++i
        }
        R--
        i = R
        if (U <= D) {
            while (i >= L) {
                res.push(g[D][i])
                --i
            }
        }
        --D
        i = D
        if (L <= R) {
            while (i >= U) {
                res.push(g[i][L])
                --i
            }
        }
        ++L
    }
    // console.log(res)
    return res
};
