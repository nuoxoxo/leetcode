/**
 * @param {string} digits
 * @return {string[]}
 */

const buttons = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]

var letterCombinations = function(d) {
    if (d.length == 0)
        return []
    res = []
    test = ""
    backtracking(d, test, res, 0)
    return res
};

function    backtracking(d, test, res, index) {
    if (index == d.length)
        res.push(test)
    else {
        // let n = d.charCodeAt(index) - 48     /// c-based approach 
        let n = parseInt(d[index])              /// js
        let i = -1

        // console.log(n)   /// debug

        while (++i < buttons[n].length) {
            test += buttons[n][i]
            backtracking(d, test, res, index + 1)
            test = test.slice(0, -1)
        }
        
    }
}
