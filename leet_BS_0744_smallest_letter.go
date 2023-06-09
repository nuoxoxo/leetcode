func nextGreatestLetter(letters []byte, target byte) byte {
	size := len(letters)
	L := 0
	R := size
	for L < R {
		mid := L + (R - L) / 2
		if letters[mid] <= target {
			L = mid + 1
		} else {
			R = mid
		}
	}
	// if R == size {
	//     return letters[0]
	// }
	// return letters[R]
	return letters[L % size]
}
