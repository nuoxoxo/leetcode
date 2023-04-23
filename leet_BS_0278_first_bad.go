/** 
 * Forward declaration of isBadVersion API.
 * @param   version   your guess about first bad version
 * @return 	 	      true if current version is bad 
 *			          false if current version is good
 * func isBadVersion(version int) bool;
 */

func firstBadVersion(n int) int {
    l := 1
    r := n
    res := r

    for l <= r {
        mid := l + (r - l) / 2
        if isBadVersion(mid) {
            res = mid
            r = mid - 1
        } else {
            l = mid + 1
        }
    }
    return res
}
