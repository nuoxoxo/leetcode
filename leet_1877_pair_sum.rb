# @param {Integer[]} nums
# @return {Integer}
def min_pair_sum(nums)
    #   Wrong:
    # nums.sort 

    n = nums.sort
    len = n.length
    res = -Float::INFINITY
    i = 0
    while i < len
        res = [res, n[i] + n[len - i - 1]].max
        i += 1
    end
    res
end
