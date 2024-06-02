class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        return [
            # backtracking_sorta, # TLE
            caching_backtracking,
        ][0](s, wordDict)

def caching_backtracking(s: str, wordDict: List[str]) -> bool:

    N = len(s)
    caching = [False] * (N + 1)
    has_cache = [False] * (N + 1)

    def possible(pos):
        if pos == N:
            return True
        if has_cache[pos]:
            return caching[pos]
        has_cache[pos] = True
        for w in wordDict:
            if s[pos:].startswith(w):
                _next = pos + len(w)
                if possible(_next):
                    caching[pos] = True
                    return True
        caching[pos] = False
        return False
    return possible(0)

def backtracking_sorta(s: str, wordDict: List[str]) -> bool:
    N = len(s)
    def possible(pos):
        if pos == N:
            return True
        for w in wordDict:
            if s[pos:].startswith(w):
                _next = pos + len(w)
                if possible(_next):
                    return True
        return False
    return possible(0)
