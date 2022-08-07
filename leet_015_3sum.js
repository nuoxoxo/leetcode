var threeSum = function(nums)
{
    let res = []
    let len = nums.length
    if (len < 3)
        return res ;
    let i = -1, j, k
    nums.sort((a, b) => {return a - b})
    while (++i < len - 2)
    {
        if (i == 0 || nums[i] != nums[i - 1])
        {
            j = i + 1
            k = len - 1
            while (j < k) {
                let tmp = nums[i] + nums[j] + nums[k]
                if (tmp == 0) {
                    res.push( [ nums[i], nums[j], nums[k] ] )
                    while (j < k && nums[j + 1] == nums[j]){
                        ++j
                    }
                    while (j < k && nums[k - 1] == nums[k]){
                        --k
                    }
                    ++j
                    --k
                } else if (tmp < 0) {
                    ++j
                } else {
                    --k
                }
            }
        }
    }
    return res
};
