function search(nums: number[], target: number): boolean {
    let n: number = nums.length
    let R: number = n - 1
    let L: number = 0
    if (R == 0) {
        if (nums[0] == target)
            return true
        return false
    }
    if (nums[L] == target || nums[R] == target) {
        return true
    }
    while (L < R && nums[L] == nums[L + 1]) {
        ++L
    }
    while (R > 0 && nums[R] == nums[R - 1]) {
        --R
    }
    while (L < R) {
        let mid: number = Math.floor((L + R) / 2)
        if (nums[mid] == target) {
            return true
        }
        if (nums[0] < nums[mid]) {
            if (nums[0] < target && target < nums[mid]) {
                R = mid
            } else {
                L = mid + 1
            }
        } else {
            if (nums[mid] < target && target < nums[n - 1]) {
                L = mid + 1
            } else {
                R = mid
            }
        }
    }
    return false
};

