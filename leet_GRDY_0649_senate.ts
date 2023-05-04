function predictPartyVictory(senate: string): string {
    let r: number[] = [], d: number[] = []
    let i: number = -1
    while (++i < senate.length) {
        let c: string = senate[i]
        if (c == 'R') {
            r.push(i)
        } else {
            d.push(i)
        }
    }
    while (r.length && d.length) {
        let rr = r.shift()
        let dd = d.shift()
        if (rr < dd) {
            r.push(i++)
        } else {
            d.push(i++)
        }
    }
    if (r.length > d.length)
        return "Radiant"
    return "Dire"
};
