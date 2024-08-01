class Solution:
    def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
        return DP(books, shelfWidth)

def DP(books: List[List[int]], shelfWidth: int) -> int:
    INF = 10**9
    N = len(books)
    cached = [[False] * (N + 1) for _ in range(N + 1)]
    caching = [[None] * (N + 1) for _ in range(N + 1)]
    def Min(idx: int, L: int, w: int, h: int) -> int:
        if idx == N:
            return h
        if cached[L][idx]:
            return caching[L][idx]
        currH = books[idx][1]
        currW = books[idx][0]
        # choice 1 - start a new row above
        Start_new = Min(idx + 1, idx, currW, currH) + h
        # choice 2 - continue on current row
        Continue = INF
        if w + currW <= shelfWidth:
            Continue = Min(idx + 1, L, w + currW, max(currH, h))
        res = min(Start_new, Continue)
        cached[L][idx] = True
        caching[L][idx] = res
        return res
    return Min(1, 0, books[0][0], books[0][1])
    
