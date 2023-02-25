    if (prices.length < 2)
        return 0
    let lowest = prices[0]
    let res = 0
    let i = -1
    while (++i < prices.length) {
        lowest = Math.min(lowest, prices[i])
        res = Math.max(res, prices[i] - lowest)
    }
    return res
