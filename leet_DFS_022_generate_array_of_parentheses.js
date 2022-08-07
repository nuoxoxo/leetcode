/**
 * @param {number} n
 * @return {string[]}
 */

var generateParenthesis = function(n){
    let candidate = ""
    let res = []
    DFS(n,n,candidate,res)
    return res
};

var DFS = function(op, cp, s, res) {
    if (op == 0 && cp == 0) {
        res.push(s)
        return
    }
    if (op != 0) {
        s += '('
        DFS(op - 1, cp, s, res)
        s = s.slice(0, -1)
    }
    if (op < cp) {
        s += ')'
        DFS(op, cp - 1, s, res)
        s = s.slice(0, -1)
    }
}
