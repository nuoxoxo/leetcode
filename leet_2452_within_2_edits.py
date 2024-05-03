class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        return [
            Bruteforce,
        ][0](queries, dictionary)

def Bruteforce(queries: List[str], dictionary: List[str]) -> List[str]:
    def hamming(L: str, R: str) -> int:
        if L == R:
            return True
        if len(L) != len(R):
            return False
        res = 0
        for l, r in zip(L, R):
            if l != r:
                res += 1
        return res
    res = []
    for q in queries:
        for d in dictionary:
            if hamming (q, d) < 3:
                res.append(q)
                break
    return res
