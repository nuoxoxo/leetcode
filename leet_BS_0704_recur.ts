function search(nums: number[], target: number): number {
    let len = nums.length
    if (len == 1) {
        return nums[0] ^ target ? -1 : 0
    }
    return helper(nums, target, 0, len - 1)
};

function helper(a: number[], target: number, L: number, R: number) : number {
    if (L > R || !a.length) {
        return -1
    }
    let mid = Math.floor((R - L) / 2) + L
    if (a[mid] == target) {
        return mid
    }
    if (a[mid] < target) {
        return helper(a, target, ++L, R)
    }
    return helper(a, target, L, --R)
};
