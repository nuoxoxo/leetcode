function lastStoneWeight(stones: number[]): number {

    // impl. priority queue

    let y: number, x: number
    while (stones.length > 1) {
        stones.sort((a, b) => b - a)
        // console.log(stones)
        y = stones.shift()
        x = stones.shift()
        stones.push(y - x)
    }
    return stones.length ? stones[0] : 0
};

