function search(nums: number[], target: number): number {
    let len = nums.length
    let r = len - 1
    let l = 0
    while (l <= r) {
        let mid = Math.floor((r - l) / 2) + l
        if (nums[mid] == target) {
            return mid
        }
        if (nums[l] < nums[mid]) {
            if (nums[l] <= target && nums[mid] >= target) {
                r = mid - 1
            } else {
                l = mid + 1
            }
        } else {
            if (nums[r] >= target && nums[mid] <= target) {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
    }
    return -1
};
