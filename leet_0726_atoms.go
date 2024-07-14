func countOfAtoms(formula string) string {

    N := len(formula)
    Q := []map[string]int{{}}
    i := 0

    for i < N {

        c := formula[i]
        if c == '(' {
            i++
            Q = append(Q, map[string]int{})
        } else if c == ')' {
            counter := Q[len(Q)-1]
            Q = Q[:len(Q)-1]
            L := i + 1
            R := i + 1
            for R < N && '0' <= formula[R] && formula[R] <= '9' {
                R++
            }
            amt := 1
            if L < R {
                temp, _ := strconv.Atoi( formula[L:R] )
                amt = max(temp, 1)
            }
            for key, prev := range counter {
                Q[len(Q)-1][key] += amt * prev
            }
            i = R
        } else if 'A' <= c && c <= 'Z' {
            key := string(c)
            L := i + 1
            R := i + 1
            for R < N && 'a' <= formula[R] && formula[R] <= 'z' {
                R++
            }
            key += formula[L:R]
            i = R
            L = R
            for R < N && '0' <= formula[R] && formula[R] <= '9' {
                R++
            }
            amt := 1
            if L < R {
                temp, _ := strconv.Atoi( formula[L:R] )
                amt = max(temp, 1)
            }
            Q[len(Q)-1][key] += amt
            i = R
        } else {
            panic("c/")
        }
    }

    counter := Q[len(Q) - 1]
    Q = Q[:len(Q) - 1]
    if len(Q) != 0 {
        panic("Q/")
    }

    keys := []string{}
    for k := range counter {
        keys = append(keys, k)
    }
    sort.Strings(keys)

    res := ""
    for _, key := range keys {
        res += key
        if counter[key] > 1 {
            res += strconv.Itoa(counter[key])
        }
    }

    return res
}
