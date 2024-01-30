func evalRPN(tokens []string) int {
    dq := []int{}
    for _, token := range tokens {
        // if t != "+" && t != "-" && t != "*" && t != "/":
        if num, err := strconv.Atoi( token ); err == nil {
            dq = append( dq, num )
        } else {
            // assert len(dq) >= 2
            L, R := dq[len(dq) - 2], dq[len(dq) - 1]
            // assert both L R are numeric
            dq = dq[:len(dq) - 2]
            var temp int
            if token == "+" {
                temp = L + R
            } else if token == "*" {
                temp = L * R
            } else if token == "-" {
                temp = L - R
            } else if token == "/" {
                // assert R != 0
                temp = L / R
            }
            // assert temp is initialized
            dq = append( dq, temp )
        }
    }
    return dq[0]
}
