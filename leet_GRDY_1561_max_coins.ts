function maxCoins(piles: number[]): number {

    piles.sort((a, b) => b - a)
    let i = 1
    let res = 0
    while (i < piles.length - Math.floor(piles.length / 3)) {
        res += piles[i]
        i += 2
    }
    return res
};
