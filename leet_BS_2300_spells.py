class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        E = [0] * len(spells)
        potions.sort()
        for i in range(len(spells)):
            l = 0
            r = len(potions) - 1
            while l <= r:
                mid = l + (r - l) // 2
                if spells[i] * potions[mid] < success:
                    l = mid + 1
                else:
                    r = mid - 1
            E[i] = len(potions) - r - 1
        return E
