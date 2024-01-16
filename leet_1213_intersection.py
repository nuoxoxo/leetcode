class Solution:
    def arraysIntersection(self, arr1: List[int], arr2: List[int], arr3: List[int]) -> List[int]:
        S = set(arr1) & set(arr2) & set(arr3)
        res = []
        for n in arr1+arr2+arr3:
            if not n in S:
                continue
            S.discard(n)
            res.append(n)
        return res
