func intToRoman(n int) string {
    vn := [13] int {1, 4, 5, 9, 
                    10, 40, 50, 90,
                    100, 400, 500, 900,
                    1000}
    vs := [13] string {"I","IV","V","IX", 
                       "X","XL","L","XC", 
                       "C","CD","D","CM", 
                       "M"};
    i := 12
    r := ""
    for true {
        tmp := n / vn[i]
        n %= vn[i]
        for tmp > 0 {
            r += vs[i]
            tmp--
        }
        i--
        if n < 1 {
            break
        }
    }
    return r
}
