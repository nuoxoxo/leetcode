class Solution:
    def sortColors(self, n: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        size = len(n)
        if size < 2:
            return
        if size is 2:
            if n[0] > n[1]:
                n[0], n[1] = n[1], n[0]
            return
        i = 0
        j = size - 1
        while n[i] is 0:
            i += 1
        while n[j] is 2:
            j -= 1
        k = i
        while k <= j:
            if n[k] is 0:
                n[k] = n[i]
                n[i] = 0
                i += 1
            elif n[k] is 2:
                n[k] = n[j]
                n[j] = 2
                j -= 1
                k -= 1
            k += 1
