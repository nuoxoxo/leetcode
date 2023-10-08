function findRelativeRanks(score: number[]): string[] {
    let sorted:number[] = [ ... score]
    sorted.sort((a, b) => b - a)
    let res: string[] = []
    for (let n of score) {

        const idx: number = sorted.indexOf(n);
        switch (idx) {
            case 0:
                res.push("Gold Medal")
                break
            case 1:
                res.push("Silver Medal")
                break
            case 2:
                res.push("Bronze Medal")
                break
            default:
                res.push((idx + 1).toString())
                break
        }
    }
    return res
};
