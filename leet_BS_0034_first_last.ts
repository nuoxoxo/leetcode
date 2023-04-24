function searchRange(nums: number[], target: number): number[] {
    let len = nums.length
    let r = len - 1
    let l = 0
    while (l <= r) {
        let mid = Math.floor((r - l) / 2) + l
        if (nums[mid] == target) {
            l = r = mid
            while (l > -1 && nums[l] == target) {
                --l
            }
            while (r < len && nums[r] == target) {
                ++r
            }
            return [l + 1, r - 1]
        }
        if (nums[mid] > target)
            r = mid - 1
        else
            l = mid + 1
    }
    return [-1, -1]
};
