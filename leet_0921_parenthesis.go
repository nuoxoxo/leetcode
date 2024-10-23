func minAddToMakeValid(s string) int {
    deque := []string{}
    for i := range s {
        char := string(s[i])
        if char == ")" && len(deque) > 0 && deque[len(deque) - 1] == "(" {
            deque = deque[:len(deque) - 1]
        } else {
            deque = append(deque, char)
        }
    }
    return len(deque)
}
