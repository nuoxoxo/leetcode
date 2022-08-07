/**
 * @param {string} directions
 * @return {number}
 */
var countCollisions = function(directions) {
    let len = directions.length
    let i = 0
    let j = len - 1
    let res = 0
    // while (directions[i] == 'L' && i < len)
    while (directions[i] == 'L' && i < len)
        ++i
    while (directions[j] == 'R' && j > -1)
        --j
    while (i <= j) {
        if (directions[i] != 'S')
            ++res
        ++i
    }
    return res
};
