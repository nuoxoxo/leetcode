class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        def count(word:str, k:int) -> int:
            N = len(word)
            res = 0
            l, conso = 0,0
            D = {}
            # D = collections.defaultdict(int)
            for r,rc in enumerate(word):
                if rc in 'aeiou':
                    if rc in D:
                        D[rc] += 1
                    else:
                        D[rc] = 1
                else:
                    conso += 1
                while len(D) == 5 and conso >= k:
                    res += N - r
                    lc = word[l]
                    if lc in 'aeiou':
                        D[lc] -= 1
                        if D[lc] == 0:
                            del D[lc]
                    else:
                        conso -= 1
                    l += 1
            return res
        return count(word, k) - count(word, k + 1)
