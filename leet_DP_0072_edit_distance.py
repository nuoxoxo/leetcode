class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        return [
            # DFS,
            BFS, # fastest
        ][0](word1, word2)

def BFS(word1: str, word2: str) -> int:
    len1 = len(word1)
    len2 = len(word2)
    Q = deque()
    Q.append((0,0))
    SEEN = set()
    res = 0
    while Q:
        N = len(Q)
        for _ in range(N):
            l, r = Q.popleft()
            # print(l,r)
            if (l, r) in SEEN:
                continue
            while l < len1 and r < len2 and word1[l] == word2[r]:
                l, r = l + 1, r + 1
            if l == len1 and r == len2:
                return res

            # insert in w1
            # advance index in w2 
            if (l, r + 1) not in SEEN:
                Q.append( (l, r + 1) )

            # replace an existing char in w1
            # advance both indexes
            if (l + 1, r + 1) not in SEEN:
                Q.append( (l + 1, r + 1) )

            # del char in w1
            if (l + 1, r) not in SEEN:
                Q.append( (l + 1, r) )
            SEEN.add( (l, r) )
        res += 1
    print('never here/')
    assert False

def DFS(word1: str, word2: str) -> int:
    len1 = len(word1)
    len2 = len(word2)

    # dp (memo)
    # l -> 0 - len1
    # r -> 0 - len2
    # dp of space -> len1 * len2
    hasCache = [[False] * (len2 + 1) for _ in range(len1 + 1)]
    cache = [[-1] * (len2 + 1) for _ in range(len1 + 1)]

    def f(l, r):
        if l == len1:
            return len2 - r
        if r == len2:
            return len1 - l
        if hasCache[l][r]:
            return cache[l][r]
        res = 1e20
        if word1[l] == word2[r]:
            res = min(res, f(l + 1, r + 1))
        res = min(res, f(l, r + 1) + 1) # insert in w1 ie. delete from w2
        res = min(res, f(l + 1, r) + 1) # delete from w1
        res = min(res, f(l + 1, r + 1) + 1) # replace

        hasCache[l][r] = True
        cache[l][r] = res
        return res

    return f(0, 0)


