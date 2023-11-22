function findDiagonalOrder(nums: number[][]): number[] {
    let D: Record<number, number[]> = []
    let r = -1, c
    while (++r < nums.length) {
        c = -1
        while (++c < nums[r].length) {
            if ( ! D.hasOwnProperty(r + c)) {
                D[r + c] = [nums[r][c]]
            } else {
                D[r + c].push(nums[r][c])
            }
        }
    }
    console.log(D)
    let res: number[] = []
    for (let [_, arr] of Object.entries(D)) {
        while (arr.length) {
            res.push(arr.pop())
        }
    }
    return res
};
