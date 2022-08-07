var summaryRanges = function(nums) {
    let len = nums.length
    let i = 0
    let E = []
    while (i < len){
        let foo = false
        let j = i
        while (j < len - 1 && nums[j] === nums[j + 1] - 1){
            if ( !foo ) foo = true
            j++
        }
        if (!foo){
            E.push(nums[j].toString())
        } else {
            E.push(nums[i].toString() + "->" + nums[j].toString())
        }
        i = j + 1
    }
    return E
};
