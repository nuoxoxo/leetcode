class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        return [
            Backtracking,
        ][0]( s )

# backtracking -
#   try evert possible partitioning
#   keeping a set to ensure a substr is seen/unique
def Backtracking(s: str) -> int:
    N = len(s)
    SEEN = set()
    # try every way to partition
    def backtrack(left: int) -> int:
        if left == N:
            return 0
        res = 0
        for right in range(left, N):
            curr = s[left : right + 1]
            if curr in SEEN:
                continue
            SEEN.add(curr)
            todo = backtrack(right + 1)
            res = max(res, todo + 1)
            SEEN.remove(curr)
        return res
    return backtrack( 0 )

