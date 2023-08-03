// import (
// 	"fmt"
// 	"strconv"
// )

var buttons = []string{
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
}

func letterCombinations(d string) []string {
	if len(d) == 0 {
		return []string{}
	}
	var res []string
	var stock string
	backtracking(d, stock, &res, 0)
	return res
}

func backtracking(d string, stock string, res *[]string, index int) {
	if index == len(d) {
		*res = append(*res, stock)
	} else {
		n, _ := strconv.Atoi(string(d[index]))
		i := 0
		for i < len(buttons[n]) {
			stock += string(buttons[n][i])
			backtracking(d, stock, res, index+1)
			stock = stock[:len(stock)-1]
			i++
		}
	}
}
