class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        D = defaultdict(int)
        for c in chars:
            D[c] += 1
        res = 0
        for w in words:
            tmp = defaultdict(int)
            for c in w:
                tmp[c] += 1
            ok = True
            for k, v in tmp.items():
                if k not in D or D[k] < v:
                    ok = False
                    break
            if ok:
                res += len(w)
        return res
