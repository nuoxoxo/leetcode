class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        res = [first]
        for n in encoded:
            first ^= n
            res.append(first)
        return res
