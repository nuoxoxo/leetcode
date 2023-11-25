function garbageCollection(garbage: string[], travel: number[]): number {
    let first: string = garbage[0]
    let gg: number = (first.match(/G/g) || []).length
    let mm: number = (first.match(/M/g) || []).length
    let pp: number = (first.match(/P/g) || []).length
    let [G, M, P] = [gg, mm, pp]
    let i = 0
    while (++i < garbage.length) {
        let t = travel[i - 1]
        let s = garbage[i]
        let [ifg, ifm, ifp] = [
            (s.match(/G/g) || []).length,
            (s.match(/M/g) || []).length,
            (s.match(/P/g) || []).length
        ]
        gg += t + ifg
        mm += t + ifm
        pp += t + ifp
        if (ifg > 0)
            G = gg
        if (ifm > 0)
            M = mm
        if (ifp > 0)
            P = pp
    }
    return G + M + P
};
