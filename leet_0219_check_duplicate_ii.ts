function containsNearbyDuplicate(nums: number[], k: number): boolean {
    let d: object = new Object()
    let i: number = -1
    while (++i < nums.length) {
        if (d.hasOwnProperty(nums[i]) && Math.abs(d[nums[i]] - i) <= k) {
            return true
        }
        d[nums[i]] = i
    }
    return false
};
