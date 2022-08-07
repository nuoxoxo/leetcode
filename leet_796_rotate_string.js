/**
 * @param {string} s
 * @param {string} goal
 * @return {boolean}
 */

var rotateString = function(s, goal) {
    if (goal == s)
        return true
    let len = s.length
    if (len ^ goal.length || len == 1)
        return false
    while (len--) {
        goal += goal[0]
        goal = goal.slice(1)
        if (goal == s)
            return true
    }
    return false
};
