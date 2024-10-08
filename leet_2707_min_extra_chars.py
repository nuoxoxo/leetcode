class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        D = collections.defaultdict(list)
        N = len(s)
        for begin in range(N):
            for word in dictionary:
                size = len(word)
                if s[begin : begin + size] == word:
                    D[begin].append(size)
        # for k, v in D.items():
            # print(k, v)
        # Step - shortest pathfinder using a DP/cost
        cost = [10 ** 20] * (N + 1)
        cost[0] = 0
        for begin in range(N):
            cost[begin + 1] = min(cost[begin + 1], cost[begin] + 1)
            for size in D[begin]:
                cost[begin + size] = min(cost[begin + size], cost[begin])
        return cost[N]
