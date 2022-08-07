class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = [words[0]]
        s = len(words)
        i = 1
        while i < s:
            L = sorted(words[i - 1])
            R = sorted(words[i])
            while L == R:
                i += 1
                if i > s - 1:
                    break
                R = sorted(words[i])
            if i > s - 1:
                break
            res.append(words[i])
            i += 1
        return res
