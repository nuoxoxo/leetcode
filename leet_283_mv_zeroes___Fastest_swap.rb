# @param {Integer[]} nums
# @return {Void} Do not return anything, modify nums in-place instead.
def move_zeroes(nums)
    len = nums.size
    if len == 0
        return 
    end
    x = 0
    for i in (0 ... len)
        if nums[i] != 0
            if i != x
                nums[i], nums[x] = nums[x], nums[i]
            end
            x += 1
        end
    end
end
