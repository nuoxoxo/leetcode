func champagneTower(poured int, query_row int, query_glass int) float64 {
    var level []float64
	level = append(level, float64(poured))
	n := 1
	for n < query_row + 1 {
		next_level := make([]float64, n + 1)
		for i := 0; i < n + 1; i++ {
			L := 0.0
			R := 0.0
			if i > 0 {
				L = level[i - 1]
			}
			if i < len(level) {
				R = level[i]
			}
			Loverflow := math.Max(0.0, L - 1.0)
			Roverflow := math.Max(0.0, R - 1.0)

			next_level[i] = 0.5 * Loverflow + 0.5 * Roverflow
		}
		level = next_level
		n++
	}
	return math.Min(1.0, level[query_glass])
}
