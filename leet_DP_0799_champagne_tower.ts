function champagneTower(poured: number, query_row: number, query_glass: number): number {
    let level:number[] = [ poured ]
    let n = 0
    while (++n < query_row + 1) {
        let next_level:number[] = Array(n + 1).fill(0)
        let i = -1
        while (++i < n + 1) {
            let L = i > 0 ? level[i - 1] : 0
            let Loverflow = Math. max(0, L - 1)
            let R = i < level.length ? level[i] : 0
            let Roverflow = Math. max(0, R - 1)
            next_level[i] = Loverflow * .5 + Roverflow * .5
        }
        level = next_level
    }
    return Math.min(1, level[query_glass])
};
