# """
# This is MountainArray's API interface.
# You should not implement it, or speculate about its implementation
# """
#class MountainArray:
#    def get(self, index: int) -> int:
#    def length(self) -> int:

class Solution:
    def findInMountainArray(self, target: int, mountain_arr: 'MountainArray') -> int:
        size = mountain_arr.length()
        l = 1
        r = size - 2
        mid = (l + r) // 2
        tip = mid
        # print('mid:', mid)
        while l <= r:
            # mid = (l + r) // 2
            mid = (r - l) // 2 + l
            L = mountain_arr.get(mid - 1)
            M = mountain_arr.get(mid)
            R = mountain_arr.get(mid + 1)
            if L < M < R: # _/^
                l = mid + 1
            elif L > M > R: # ^\_
                r = mid - 1
            else:
                break
        tip = mid
        l = 0
        r = tip
        while l <= r:
            mid = (r - l) // 2 + l
            n = mountain_arr.get(mid)
            if n == target:
                return mid
            if n < target:
                l = mid + 1
            else:
                r = mid - 1
        l = tip
        r = size - 1
        # print(tip)
        while l <= r:
            mid = (r - l) // 2 + l
            n = mountain_arr.get(mid)
            # print(mid, l, r)
            # checking against:
            """
            [1,5,2]
            2
            """
            if n == target:
                return mid
            if n > target:
                l = mid + 1
            else:
                r = mid - 1
        return -1

