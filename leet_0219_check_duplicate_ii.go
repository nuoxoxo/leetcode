func containsNearbyDuplicate(nums []int, k int) bool {

    d := make(map[int] int)

    for i, v := range nums {
        if _, has := d[v]; has {
            if i - d[v] <= k {
                return true
            }
        }
        d[v] = i
    }
    return false

    // template: ts soln

    /*
    let d: object = new Object()
    let i: number = -1
    while (++i < nums.length) {
        if (d.hasOwnProperty(nums[i]) && Math.abs(d[nums[i]] - i) <= k) {
            return true
        }
        d[nums[i]] = i
    }
    return false
    */
}
