/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    let n = nums.length
    if (n == 1) return nums[0]
    if (n == 2) return Math.max(nums[1], nums[0])
    if (n == 3) return Math.max(nums[1], nums[0] + nums[2])
    let G = new Array(n)
    let i = 2
    G[0] = nums[0]
    G[1] = nums[1]
    G[2] = Math.max(nums[1], nums[0] + nums[2])
    while (++ i < n)
        G[i] = Math.max(nums[i] + G[i - 2], nums[i] + G[i - 3])
    return Math.max(G[i - 1], G[i - 2])
}; 
