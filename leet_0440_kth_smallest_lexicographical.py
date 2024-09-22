class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        return [
            # Iterative_0386, // TLE
            # DFS_0386, // TLE
            # f,
        ][0](n, k)

def f (n: int, k: int) -> int:
    def count_from_curr(curr):
        res = 0
        neighbor = curr + 1
        while curr <= n:
            res += min(neighbor, n + 1) - curr
            neighbor *= 10
            curr *= 10
        return res
    curr = 1
    i = 1
    while i < k:
        count = count_from_curr(curr)
        if count + i <= k:
            i += count
            curr += 1
        else:
            curr *= 10
            i += 1
    return curr

def DFS_0386(n: int, k: int) -> int:
    def dfs(n:int) -> List[int]:
        res = []
        def DFS(curr):
            if curr > n:
                return
            res.append(curr)
            for i in range(min(n + 1, 10)):
                DFS(curr * 10 + i)
        for curr in range(1, min(n + 1, 10)):
            if curr > n:
                break
            DFS(curr)
        return res
    return dfs(n)[k - 1]

def Iterative_0386(n: int, k: int) -> int:
    res = []
    todo = 1
    for _ in range(n):
        res.append( todo )
        if todo <= n:
            todo *= 10
        if todo > n:
            todo //= 10
            if todo == n:
                todo //= 10
            todo += 1
            while todo % 10 == 0:
                todo //= 10
    return res[k - 1]
