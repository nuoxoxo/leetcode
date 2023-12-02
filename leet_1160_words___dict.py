class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        D = {}
        for c in chars:
            if c in D:
                D[c] += 1
            else:
                D[c] = 1
        res = 0
        for w in words:
            tmp = {}
            for c in w:
                if c in tmp:
                    tmp[c] += 1
                else:
                    tmp[c] = 1
            ok = True
            for k, v in tmp.items():
                if k not in D or D[k] < v:
                    ok = False
                    break
            if ok:
                # print(w)
                res += len(w)
        return res
