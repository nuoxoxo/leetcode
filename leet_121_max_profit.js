/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    if (prices.length == 1)
        return 0
    let lowest = prices[0]
    let margin = 0
    for (let p of prices){
        lowest = Math.min(p,  lowest)
        margin = Math.max(p - lowest, margin)
    }
    return margin
};
