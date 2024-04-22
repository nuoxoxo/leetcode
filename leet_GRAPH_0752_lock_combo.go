func openLock(deadends []string, target string) int {

    Solutions := []func([]string, string) int {
        BFS,
    }
    return Solutions[0](deadends, target)
}

func BFS(deadends []string, target string) int {

    code := "0000"
    nogo := map[string]bool{}
    for _, end := range deadends {
        if end == code || end == target {
            return -1
        }
        nogo[end] = true
    }
    steps := map[string]int{code: 0}
    deque := []string{code}
    for len(deque) > 0 {
        code = deque[0]
        if code == target {
            return steps[code]
        }
        deque = deque[1:]
        i := 0
        for i < 4 {
            n := int(code[i] - '0')
            for _, offset := range []int{-1, 1} {
                // d := (n + offset) % 10
                // -1 mod 10 won't work for Go
                d := (n + offset + 10) % 10
                digit := string(d + '0')
                _new := code[:i] + digit + code[i + 1:]
                if _new == target {
                    return steps[code] + 1
                }
                if nogo[_new] {
                    continue
                }
                if _, exists := steps[_new]; exists {
                    continue
                }
                steps[_new] = steps[code] + 1
                deque = append(deque, _new)
            }
            i++
        }
    }
    return -1
}
