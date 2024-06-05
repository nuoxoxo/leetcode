class Solution:
    def commonChars(self, words: List[str]) -> List[str]:
        return [
            # Initial_soln,
            Double_list,
        ][0](words)

def Double_list(words: List[str]) -> List[str]:
    counter = [1e9] * 26 # keep track of minimum occurrence
    for w in words:
        cur = [0] * 26
        for c in w:
            idx = ord(c) - ord('a')
            cur[idx] += 1
        counter = [min(counter[i], cur[i]) for i in range(26)]
    return [chr(ord('a') + i) for i, t in enumerate(counter) for _ in range(t) if t]

def Initial_soln(words: List[str]) -> List[str]:
    s = collections.Counter(words[0])
    for i in range(1, len(words)):
        s &= collections.Counter(words[i])
    res = []
    for k, v in s.items():
        res += [k] * v
    return res

