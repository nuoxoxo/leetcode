var moveZeroes = function(nums) {
    let imove = -1, izero = 0
    while (++imove < nums.length){
        if (nums[imove] ^ 0){
            if (imove ^ izero){
                nums[izero] = nums[imove]
                nums[imove] = 0
            }
            izero++
        }
    }
};
