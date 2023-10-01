function kWeakestRows(mat: number[][], k: number): number[] {
    let res:number[] = []
    let v:number[][] = []
    let i = -1
    let len = mat.length
    while (++i < len) {
        let temp = 0
        for (let n of mat[i])
            temp += n
        v.push([temp, i])
    }
    v.sort((a, b) => a[0] != b[0] ? a[0] - b[0] : a[1] - b[1])
    i = -1
    while (++i < k) {
        res.push(v[i][1])
    }
    return res
};
