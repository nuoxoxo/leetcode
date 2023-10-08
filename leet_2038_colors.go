func winnerOfGame(colors string) bool {
    if len(colors) < 3 {
		return false
	}
	a, b := 0, 0
	for i := 1; i < len(colors) - 1; i++ {
		if colors[i - 1] == colors[i] && colors[i] == colors[i + 1] {
			if colors[i] == 'A' {
				a++
			} else {
				b++
			}
		}
	}

	return a > b
}
