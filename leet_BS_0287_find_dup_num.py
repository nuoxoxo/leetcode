class Solution:
    def findDuplicate(self, n: List[int]) -> int:
        L = len(n)
        if L is 2:
            return n[0]
        n.sort()
        i = 1
        j = L - 2
        mid = L // 2
        while i != j and i < mid and j > mid:
            if n[i] == n[i - 1]:
                return n[i]
            if n[j] == n[j + 1]:
                return n[j]
            i += 1
            j -= 1
        return n[mid]
