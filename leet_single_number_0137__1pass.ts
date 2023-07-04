function singleNumber(nums: number[]): number {
    let len:number = nums.length
    if (len == 1) {
        return nums[0]
    }
    nums.sort((a, b) => {return a - b})
    if (nums[0] ^ nums[1]) {
        return nums[0]
    }
    let i:number = -1
    while (++i < nums.length) {
        if (nums[i] ^ nums[i + 1] && nums[i + 1] ^ nums[i + 2])
            break
    }
    return nums[i + 1]
    
};
