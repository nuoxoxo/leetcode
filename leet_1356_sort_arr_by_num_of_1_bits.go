func sortByBits(arr []int) []int {
   sort.Slice(arr, func(i, j int) bool {
		a := arr[i]
        x := 0
        for a != 0 {
            x += a & 1
            a >>= 1
        }
        b := arr[j]
		y := 0
        for b != 0 {
            y += b & 1
            b >>= 1
        }
		if x == y {
			return arr[i] < arr[j]
		}
		return x < y
	})
	return arr 
}
