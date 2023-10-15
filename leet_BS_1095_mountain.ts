/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *      get(index: number): number {}
 *
 *      length(): number {}
 * }
 */

function findInMountainArray(target: number, mountainArr: MountainArray) {
    let len = mountainArr.length()
    let l = 1
    let r = len - 2
    let mid = Math.floor((r - l) / 2) + l
    let peak = mid
    while (l <= r) {
        mid = Math.floor((r - l) / 2) + l
        let L = mountainArr.get(mid - 1)
        let R = mountainArr.get(mid + 1)
        let M = mountainArr.get(mid)
        if (L < M && M < R) { // _/^
            l = mid + 1
        } else if (L > M && M > R) { // ^\_
            r = mid - 1
        } else {
            break
        }
    }
    peak = mid
    l = 0
    r = peak
    while (l <= r) {
        mid = Math.floor((r - l) / 2) + l
        let M = mountainArr.get(mid)
        if (M == target) {
            return mid
        } if (M < target) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    l = peak
    r = len - 1
    while (l <= r) {
        mid = Math.floor((r - l) / 2) + l
        let M = mountainArr.get(mid);
        if (M == target) {
            return mid
        } if (M > target) {
            l = mid + 1
        } else {
            r = mid - 1
        }
    }
    return -1
};
