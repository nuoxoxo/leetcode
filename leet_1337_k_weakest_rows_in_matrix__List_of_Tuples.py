class Solution:
    def kWeakestRows(self, mat: List[List[int]], k: int) -> List[int]:
        n = len(mat)
        res = []
        arr = []
        for i in range(n):
            tmp = sum(mat[i])
            arr.append((tmp, i))
        arr.sort()
        for i in range(k):
            res.append(arr[i][1])
        return res            
