var findPeakElement = function(nums){
    let copy = [...nums].sort((a,b) => {return a - b})
    return nums.indexOf(copy[copy.length - 1])
};
