func diffWaysToCompute(expression string) []int {
    Solutions := []func(string) []int {
        Using_catalan_number,
    }
    return Solutions[0](expression)
}

func Using_catalan_number(expression string) []int{
    
    // Step - tokenize
    var tokens []interface{}
    num := ""
    for _, c := range expression {
        if '0' <= c && c <= '9' {
            num += string(c)
        } else {
            if num != "" {
                n, _ := strconv.Atoi(num)
                tokens = append(tokens, n)
                num = ""
            }
            // assert char in '+-*'
            tokens = append(tokens, string(c))
        }
    }
    if num != "" {
        n, _ := strconv.Atoi(num)
        tokens = append(tokens, n)
    }
    // Step - recursive bruteforce
    var f func(L, R int) []int
    f = func (L, R int) []int {
        if L == R {
            return []int{tokens[L].(int)}
        }
        res := []int{}
        mid := L + 1
        for mid < R {
            left_res := f(L, mid - 1)
            right_res := f(mid + 1, R)
            op := tokens[mid].(string)
            for _, l := range left_res {
                for _, r := range right_res {
                    if op == "+" {
                        res = append(res, l + r)
                    } else if op == "-" {
                        res = append(res, l - r)
                    } else if op == "*" {
                        res = append(res, l * r)
                    }
                }
            }
            mid += 2
        }
        return res
    }
    return f(0, len(tokens) - 1)
}
