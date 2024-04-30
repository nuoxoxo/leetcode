class Solution:
    def wonderfulSubstrings(self, word: str) -> int:
        return [
            # self.DP_Bitmask_PrefixSum,
            self.Larry_DP_Bitmask_PrefixSum,
        ][0](word)

    def Larry_DP_Bitmask_PrefixSum(self, word: str) -> int:
        D = defaultdict(int)
        D[0] = 1
        res = 0
        state = 0
        for c in word:
            POS = ord(c) - ord('a')
            state ^= (1 << POS)
            res += D[state]
            D[state] += 1
            for k in range(10): # statement dictates
                state ^= (1 << k)
                res += D[state]
                state ^= (1 << k)
        return res

    def DP_Bitmask_PrefixSum(self, word:str) -> int:
        a = ord('a')
        N = ord('j') - a + 1
        assert N == 10
        D = defaultdict(int)
        # D = [0] * (1 << N) ### Eqv. D = defaultdict(int)
        D[0] = 1
        res = 0
        state = 0
        for c in word:
            pos = ord(c) - a

            state = state ^ (1 << pos)
            # State's i'th pos flipped, ie. state[i] flipped 

            res += D[state] # all freq are even
            for k in range(N):
                state ^= (1 << k)
                res += D[state]
                state ^= (1 << k)
            D[state] += 1
        return res

        """
        a = ord('a')
        N = ord('j') - a + 1
        assert N == 10
        Odds = [0] * N
        Freq = defaultdict(int)
        res = 0
        for c in word:
            dig = ord(c) - a
            Odds[dig] ^= 1

        print(Odds)
        return res
        """
# 525 930 1542 1524
"""
       v
XXXXXXXXXX
"""
"""
- "aabb" -> "aabb"
    v
- "aabb" -> "a"
     v
- "aabb" -> "aa"
      v
- "aabb" -> "aab"
    vv
- "aabb" -> "a"
    v v
- "aabb" -> "abb"
     vv
- "aabb" -> "b"
     v
- "aabb" -> "bb"
      v
- "aabb" -> "b"
"""
