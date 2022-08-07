var searchRange = function(nums, target) {
    // if (!nums.includes(target))
    //     return [-1, 1]

    /* js indexOF & lastIndexOf return -1 on basecase */

    return [ nums.indexOf(target), nums.lastIndexOf(target) ]
};
