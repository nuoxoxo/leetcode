class Solution:
    def nextGreatestLetter(self, letters: List[str], target: str) -> str:
        n = len(letters)
        i = 0
        j = n
        while i < j:
            mid = (j - i) // 2 + i
            if letters[mid] <= target:
                i = mid + 1
            else:
                j = mid
        if j == n:
            return letters[0]
        return letters[j]
