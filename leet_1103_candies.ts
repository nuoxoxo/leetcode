function distributeCandies(candies: number, num_people: number): number[] {
    let res:number[] = new Array(num_people).fill(0)
    let idx:number = 0
    let c: number = 0
    let n: number
    while (++c && candies > 0) {
        n = Math.min(candies, c)
        candies -= n
        res[idx] += n
        idx = (idx + 1) % num_people
    }
    return res
};
