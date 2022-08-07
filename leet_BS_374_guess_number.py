# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num: int) -> int:

class Solution:
    def guessNumber(self, n: int) -> int:
        def recurse(L: int, R: int) -> int:
            mid = (L + R) // 2
            if guess(mid) == 0:
                return mid
            if guess(mid) < 0:
                return recurse(L, mid - 1)
            if guess(mid) > 0:
                return recurse(mid + 1, R)
        return recurse(1, n)
            
