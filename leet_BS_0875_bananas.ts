function minEatingSpeed(piles: number[], h: number): number {
    piles.sort((a, b) => a - b)
    let M = piles[piles.length - 1]
    let L = 1
    let R = M
    let res = M
    while (L < R) {
        let hours = 0
        let mid = Math.floor((R - L) / 2) + L
        for (let p of piles) {
            hours += Math.ceil(p / mid)
        }
        if (hours > h) {
            L = mid + 1
        } else {
            res = Math.min(res, mid)
            R = mid
        }
    }
    return res
};
