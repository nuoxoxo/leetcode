/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function(isBadVersion: any) {

    return function(n: number): number {
        let helper = (l: number, r: number, ptr: number) : number => {
            if (l > r) {
                return ptr
            }
            let mid = Math.floor((r - l) / 2) + l
            if (isBadVersion(mid)) {
                ptr = mid
                return helper(l, mid - 1, ptr)
            }
            return helper(mid + 1, r, ptr)
        }
        return helper(0, n, n)
    };
};
