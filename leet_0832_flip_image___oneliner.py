class Solution:
    def flipAndInvertImage(self, e: List[List[int]]) -> List[List[int]]:
        return [[1 if n == 0 else 0 for n in _[::-1]] for _ in e]
