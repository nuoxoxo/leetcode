/**
 * @param {number} num
 * @return {number}
 */

var numberOfSteps = function(num) {
    return solve(num, 0)
};

var solve = function(n, c) {
    if (n == 0)
        return c
    if (n % 2 == 0)
        return solve(n / 2, ++c)
    return solve(--n, ++c)
}
