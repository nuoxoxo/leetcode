function find132pattern(nums: number[]): boolean {
    let mid:number = Number.MIN_SAFE_INTEGER
    let D:number[] = []
    let i = nums.length
    while (--i > -1) {
        let L = nums[i]
        if (L < mid)
            return true
        while (D.length !== 0 && L > D[D.length - 1]) {
            mid = D.pop()
        }
        D.push(L)
    }
    return false
};
