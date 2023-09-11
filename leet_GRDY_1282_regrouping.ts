function groupThePeople(groupSizes: number[]): number[][] {
    let res = []
    let D = {}
    let i = -1
    while (++i < groupSizes.length) {
        let len = groupSizes[i]
        if ( !D.hasOwnProperty(len)) {
            D[len] = []
        }
        D[len]!.push(i)
        if ( D[len].length === len) {
            res.push(D[len])
            D[len] = []
        }
    }
    return res
};
