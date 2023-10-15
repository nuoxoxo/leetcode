/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 *  struct MountainArray;
 *  impl MountainArray {
 *     fn get(index:i32)->i32;
 *     fn length()->i32;
 * };
 */

impl Solution {
    pub fn find_in_mountain_array(target: i32, mountainArr: &MountainArray) -> i32 {
        let len = mountainArr.length();
        let mut l = 1;
        let mut r = len - 2;
        let mut mid = (r - l) / 2 + l;
        let mut peak = mid;

        while l <= r {
            mid = (r - l) / 2 + l;
            let ll = mountainArr.get(mid - 1);
            let rr = mountainArr.get(mid + 1);
            let mm = mountainArr.get(mid);

            if ll < mm && mm < rr {
                l = mid + 1;
            } else if ll > mm && mm > rr {
                r = mid - 1;
            } else {
                break;
            }
        }
        peak = mid;
        l = 0;
        r = peak;

        while l <= r {
            mid = (r - l) / 2 + l;
            let mm = mountainArr.get(mid);

            if mm == target {
                return mid;
            }
            if mm < target {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        l = peak;
        r = len - 1;

        while l <= r {
            mid = (r - l) / 2 + l;
            let mm = mountainArr.get(mid);

            if mm == target {
                return mid;
            }
            if mm > target {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        -1
    }
}
