/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * type MountainArray struct {
 * }
 *
 * func (this *MountainArray) get(index int) int {}
 * func (this *MountainArray) length() int {}
 */

func findInMountainArray(target int, mountainArr *MountainArray) int {
    len := mountainArr.length()
	l := 1
	r := len - 2
	mid := (r-l)/2 + l
	peak := mid

	for l <= r {
		mid = (r-l)/2 + l
		L := mountainArr.get(mid - 1)
		R := mountainArr.get(mid + 1)
		M := mountainArr.get(mid)

		if L < M && M < R {
			l = mid + 1
		} else if L > M && M > R {
			r = mid - 1
		} else {
			break
		}
	}

	peak = mid
	l = 0
	r = peak
	for l <= r {
		mid = (r-l)/2 + l
		M := mountainArr.get(mid)

		if M == target {
			return mid
		}
		if M < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	l = peak
	r = len - 1

	for l <= r {
		mid = (r-l)/2 + l
		M := mountainArr.get(mid)

		if M == target {
			return mid
		}
		if M > target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}

	return -1
}
