function containsDuplicate(nums: number[]): boolean {
    let s: Set<number> = new Set()
    for (let n of nums) {
        if (s.has(n))
            return true
        s.add(n)
    }
    return false
};
