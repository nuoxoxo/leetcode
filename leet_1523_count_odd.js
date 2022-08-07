var countOdds = function(low, high) {
    dif = Math.floor((high - low) / 2)
    if (high % 2 || low % 2)
        return dif + 1
    return dif
};
