func judgeSquareSum(c int) bool {

    solutions := []func(int)bool{
        // Complement_set,
        Binary_search,
    }
    return solutions[0](c)
}

func Binary_search(c int) bool {

    L, R := uint64(0), uint64(math.Sqrt(float64(c)))
    for L <= R {
        lhs := R*R + L*L
        if lhs == uint64(c) {
            return true
        }
        if lhs < uint64(c) {
            L++
        } else {
            R--
        }
    }
    return false
}

func Complement_set(c int) bool {
    seen := make(map[int]bool)
    n := 0
    for n <= int(math.Sqrt(float64(c))) {
        sq := n * n
        seen[sq] = true
        complt := c - sq
        if seen[complt] {
            return true
        }
        n++
    }
    return false
}

