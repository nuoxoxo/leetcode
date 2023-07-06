# @param {Integer[]} nums
# @return {Integer}
def longest_subarray(nums)
    tt = 1
    l = 0
    r = -1
    while r < nums.length - 1
        r += 1
        if nums[r] == 0
        tt -= 1
        end
        if tt < 0
        if nums[l] == 0
            tt += 1
        end
        l += 1
        end
    end
    return nums.length - 1 - l
end
