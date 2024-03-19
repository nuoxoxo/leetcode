class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        N = len(tasks)
        D = [0] * 26
        for c in tasks: D[ord(c) - ord('A')] += 1
        D.sort(reverse=True)
        segments, mustcool = D[0] - 1, (D[0] - 1) * n
        for i in range(1, 26): mustcool -= min(segments, D[i])
        return N + mustcool if mustcool > 0 else N
