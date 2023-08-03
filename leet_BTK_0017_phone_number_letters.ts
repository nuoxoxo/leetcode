const buttons = [
    "", 
    "", 
    "abc", 
    "def", 
    "ghi", 
    "jkl", 
    "mno", 
    "pqrs", 
    "tuv",
    "wxyz"
]

function letterCombinations(d: string): string[] {

    if (d.length == 0)
        return []
    let res: string[] = []
    let stock: string = ""
    backtracking(d, stock, res, 0)
    return res
};

function    backtracking(d, stock: string, res, index) {
    if (index == d.length) {
        res.push(stock)
    } else {
        let n = parseInt(d[index])
        let i = -1
        // console.log(n)   // debug
        while (++i < buttons[n].length) {
            stock += buttons[n][i]
            backtracking(d, stock, res, index + 1)
            stock = stock.slice(0, -1)
        }
        
    }
}
