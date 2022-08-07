var canMakeArithmeticProgression = function(arr) {
    let s = arr.length
    if ( s < 3 )
        return true
    let i = -1
    arr.sort((a, b) => {return a - b})
    console.log(arr)
    while (++i < s - 2)
        if (arr[i] - arr[i + 1] != arr[i + 1] - arr[i + 2])
            return false
    return true
};
