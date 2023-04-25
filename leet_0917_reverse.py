class Solution:
    def reverseOnlyLetters(self, s: str) -> str:
        a = [_ for _ in s]
        l = 0
        r = len(a) - 1
        while l < r:
            if a[l].isalpha() and a[r].isalpha():
                a[l], a[r] = a[r], a[l]
                l += 1
                r -= 1
            elif not a[l].isalpha():
                l += 1
            elif not a[r].isalpha():
                r -= 1
        return ''.join(a)
