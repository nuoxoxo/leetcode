function minOperations(nums: number[], k: number): number {
    let S = new Set()
    let res = 0
    let i = 0
    while (++i < k + 1)
        S.add(i)
    while (S.size) {
        let n = nums.pop()
        if (S.has(n))
            S.delete(n)
        res++
    }
    return res
};
