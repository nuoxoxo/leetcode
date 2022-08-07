/**
 * @param {number[]} prices
 * @return {number}
 */

var maxProfit = function(prices) {
    i = 0
    res = 0
    while (++i < prices.length){
        if (prices[i] > prices[i - 1])
            res += prices[i] - prices[i - 1]
    }
    return res
};
