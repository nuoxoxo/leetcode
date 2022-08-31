/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    return recurse(0, n, n);
}

func recurse(l int, r int, curr int) int {
    if l > r {
        return curr
    }
    mid := l + (r - l) / 2
    if isBadVersion(mid) {
        curr = mid
        return recurse(l, mid - 1, curr)
    }
    return recurse(mid + 1, r, curr)
}
