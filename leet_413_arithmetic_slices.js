var numberOfArithmeticSlices = function(nums) {
    let len = nums.length
    if (len < 3)
        return 0
    let i = -1, res = 0
    while (++i < len - 2){
        let dif = nums[i + 1] - nums[i]
        let j = i + 1
        while (++j < len){
            if (nums[j] - nums[j - 1] ^ dif)
                break
            else
                ++res
        }
    }
    return res
};
