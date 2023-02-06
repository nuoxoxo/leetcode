function shuffle(nums: number[], n: number): number[] {
    let r = []
    for (let i = 0; i < n; i++) {
        r.push(...(new Array(nums[i], nums[i + n])))
    }
    return r
};
