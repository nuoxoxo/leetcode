class Solution:
    def coinChange(self, coins: List[int], n: int) -> int:
        if n == 0:
            return n
        seen = set()    # seen = set([n]) ## works too
        dq = [(0, 0)]
        while dq:
            curr, level = dq.pop(0)
            if level != 0 and curr == n:
                return level
            for c in coins:
                if c + curr not in seen and c + curr <= n:
                    dq.append((curr + c, level + 1))
                    seen.add(curr + c)
        return -1
