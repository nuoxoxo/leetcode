func integerBreak(n int) int {
    if n < 4 {
		return n - 1
	}
	quo := n / 3
	rem := n % 3
	if rem == 2 {
		return power(3, quo) * 2
	}
	if rem == 1 {
		return power(3, quo-1) * 4
	}
	return power(3, quo)
}

func power(l int, r int) int {
	res := 1
	for i := 0; i < r; i++ {
		res *= l
	}
	return res
}
