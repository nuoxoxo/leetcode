class Solution:
    def maxScoreWords(self, words: List[str], letters: List[str], score: List[int]) -> int:

        N = len(words)         
        counts = collections.Counter(letters)
        frequencies = [0] * N
        for i, w in enumerate(words):
            frequencies[i] = collections.Counter(w)
        a = ord('a')

        @cache
        def get_score(idx):
            freq = frequencies[idx]
            res = 0
            for char, times in freq.items():
                asc = ord(char) - a
                res += score[asc] * times
            return res

        def backtrack(L, counts):
            if L == N:
                return 0

            # next index
            R = L + 1

            # skip
            res = max(0, backtrack(R, counts))

            # take
            freq = frequencies[L]

            if counts >= freq:
                counts -= freq
                score = get_score(L)
                trial = backtrack(R, counts)
                res = max(res, trial + score)
                counts += freq
            return res

        return backtrack(0, counts)
