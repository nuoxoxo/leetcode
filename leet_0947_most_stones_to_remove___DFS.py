class Solution:
    def removeStones(self, stones: List[List[int]]) -> int:
        def DFS(index: int) -> None:
            size = len(stones)
            v[index] = True
            for i in range(n):
                if not v[i] and (stones[i][0] == stones[index][0] 
                              or stones[i][1] == stones[index][1]):
                    DFS(i)
        res = 0
        n = len(stones)
        v = [False] * n
        for i in range(n):
            if not v[i]:
                res += 1
                DFS(i)
        return n - res
