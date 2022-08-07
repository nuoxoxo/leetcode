/**
 * @param {string} s
 * @return {number}
 */
var scoreOfParentheses = function(s) {
    let score = 0
    let d = []
    for (let c of s){
        if (c == '(') {
            d.push(score)
            score = 0
        } else {
            score += d.pop() + Math.max(score, 1)
        }
    }
    return score 
};
