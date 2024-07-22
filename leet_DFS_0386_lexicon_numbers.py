class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        return [
            iterative,
            # dfs, # initial soln
        ][0](n)

def iterative(n:int) -> List[int]:
    res = []
    todo = 1
    for _ in range(n):
        res.append( todo )
        if todo <= n:
            todo *= 10
        if todo > n:
            todo //= 10
            if todo >= n:
                todo //= 10
            todo += 1
            while todo % 10 == 0:
                todo //= 10
    return res

def dfs(n:int) -> List[int]:
    res = []
    def DFS(curr):
        if curr > n:
            return
        res.append(curr)
        for i in range(10):
            DFS(curr * 10 + i)
    for i in range(1, 10):
        if i > n:
            break
        DFS(i)
    return res
