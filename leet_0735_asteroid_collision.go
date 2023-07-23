func asteroidCollision(/*asteroids*/ A []int) []int {
    var dq []int
    i := 0
	for i < len(A) {
        a := A[i]
		if len(dq) == 0 || a > 0 || dq[len(dq) - 1] < 0 {
            dq = append(dq, a)
            i += 1
        } else if dq[len(dq) - 1] + a == 0 {
            dq = dq[:len(dq) - 1]
            i += 1
        } else if dq[len(dq) - 1] + a < 0 {
            dq = dq[:len(dq) - 1]
        } else {
            i += 1
        }
	}
	return dq
}
