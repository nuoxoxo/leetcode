func garbageCollection(garbage []string, travel []int) int {
    first := garbage[0]
	gg, mm, pp := strings.Count(first, "G"), strings.Count(first, "M"), strings.Count(first, "P")
	G, M, P := gg, mm, pp

	for i := 1; i < len(garbage); i++ {

		t := travel[i-1]
		s := garbage[i]
		ifg, ifm, ifp := strings.Count(s, "G"), strings.Count(s, "M"), strings.Count(s, "P")
		gg += t + ifg
		mm += t + ifm
		pp += t + ifp

		if ifg > 0 {
			G = gg
		}
		if ifm > 0 {
			M = mm
		}
		if ifp > 0 {
			P = pp
		}
	}

	return G + M + P
}
