class Solution:
    def addToArrayForm(self, num: List[int], k: int) -> List[int]:
        i = len(num) - 1
        r = []
        while i > -1 or k is not 0:
            if i > -1:
                k += num[i]
            r.append(k % 10)
            k //= 10
            i -= 1
        return reversed(r)
