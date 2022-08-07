var arraySign = function(nums){
    //if ( nums.includes(0) ) return 0
    let sign = 1
    for (let i of nums){
        if (i < 0)  sign *= -1
        if (i == 0) return 0
    }
    return sign < 0 ? -1 : 1
};

/*
var arraySign = function(nums){
    let sign = 1
    for (let i of nums){
        if (i < 0)  sign *= -1
        if (i == 0) return 0
    }
    return sign < 0 ? -1 : 1
};
*/
