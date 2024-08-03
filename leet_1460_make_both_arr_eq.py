class Solution:
    def canBeEqual(self, target: List[int], arr: List[int]) -> bool:
        return sorted(arr) == sorted(target)
        # return collections.Counter(arr) == collections.Counter(target)
"""
[1,2,3,4]
[2,4,1,3]
[7]
[7]
[3,7,9]
[3,7,11]
[1,1,1,1,1]
[1,1,1,1,1]
[1,2,3]
[2,2,2]
"""
