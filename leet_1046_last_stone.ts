function lastStoneWeight(stones: number[]): number {
    while (stones.length > 2) {
        let x = secondBiggest(stones)
        let y = Math.max(...stones)
        // console.log(y, x, stones.length)
        if (x ^ y) {
            stones[stones.indexOf(y)] = y - x
            stones.splice(stones.indexOf(x), 1)
        } else {
            stones.splice(stones.indexOf(x), 1)
            stones.splice(stones.indexOf(y), 1)
        }
    }
    if (stones.length == 2) {
        return Math.abs(stones[0] - stones[1])
    }
    if (stones.length == 1)
        return stones[0]
    return 0
};

let secondBiggest = (arr: number[]): number => {
    let max = -Infinity
    let res = -Infinity
    for (let n of arr) {
        if (max < n) {
            res = max
            max = n
        } else if (max >= n && res <= n) {
            res = n
        }
        // console.log(max, res)
    }
    return res
}
