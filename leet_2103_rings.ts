function countPoints(rings: string): number {
    let E = new Object()
    let i = 0
    while (i < rings.length - 1) {
        if (E.hasOwnProperty(rings[i + 1])) {
            E[rings[i + 1]] += rings[i]
        } else {
            E[rings[i + 1]] = rings[i]
        }
        i += 2
    }
    let count = 0
    for (let e of Object.values(E)) {
        let s = new Set(e)
        if (s.size == 3)
            count++
        // console.log(e)
    }
    return count
};
