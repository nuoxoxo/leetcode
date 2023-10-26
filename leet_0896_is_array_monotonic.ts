function isMonotonic(nums: number[]): boolean {
    let len:number = nums.length
    if (len < 3)
        return true
    let flag = 0
    let i = -1
    while (++i < len - 1){
        if (!flag) {
            if (nums[i] < nums[i + 1])
                flag = 1
            if (nums[i] > nums[i + 1])
                flag = 2
        } else if ((flag == 1 && nums[i] > nums[i + 1]) ||
                flag == 2 && nums[i] < nums[i + 1])
            return false
    }
    return true 
};
