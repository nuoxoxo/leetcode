func searchInsert(nums []int, target int) int {
    l := 0
    r := len(nums) - 1
    for l <= r {
        mid := (r - l) / 2 + l
        if nums[mid] == target {
            return mid
        }
        if (nums[mid] < target) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return l
}

// JS soln

/*
function searchInsert(nums: number[], target: number): number {
    let L = 0
    let R = nums.length - 1
    while (L <= R) {
        let m = Math.floor((R - L) / 2) + L
        if (nums[m] == target)
            return m
        else if (nums[m] < target)
            L = m + 1
        else
            R = m - 1
    }
    return L
}
*/
