/**
 * The knows API is defined in the parent class Relation.
 * isBadVersion(version: number): boolean {
 *     ...
 * };
 */

var solution = function(isBadVersion: any) {

    return function(n: number): number {
       let l = 0
       let r = n
       let res = r
       while (l <= r) {
           let mid = Math.floor((r - l) / 2) + l
           if (isBadVersion(mid)) {
               res = mid
               r = mid - 1
           } else {
               l = mid + 1
           }
       }
       return res
    };
};
