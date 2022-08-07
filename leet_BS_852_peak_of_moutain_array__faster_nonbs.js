var peakIndexInMountainArray = function(a) {
    i = 0
    while (a[i] < a[i + 1])
        ++ i
    return i
};
