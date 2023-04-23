function search(nums: number[], target: number): number {
    let len = nums.length
    if (len == 1) {
        return nums[0] == target ? 0 : -1
    }
    let L = 0
    let R = len - 1
    while (L <= R) {
        let mid = Math.floor((R - L) / 2) + L
        if (nums[mid] == target) {
            return mid
        }
        if (nums[mid] < target) {
            ++L
        } else {
            --R
        }
    }
    return -1
};
