class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        return [
            self.iterative_fill,
        ][0](land)

    def iterative_fill(self, land) -> List[List[int]]:
        R, C = len(land), len(land[0])
        Seen = set()
        res = []
        for r in range(R):
            for c in range(C):
                if land[r][c] == 1 and (r, c) not in Seen:
                    er, ec = r, c
                    # no need to check set bc. it says 
                    #   "no two groups are adjacent"
                    while er + 1 < R and land[er + 1][ec] == 1:# and (er + 1, ec) not in Seen:
                        er += 1
                    while ec + 1 < C and land[er][ec + 1] == 1:# and (er, ec + 1) not in Seen:
                        ec += 1
                    res.append([r, c, er, ec])
                    for i in range(r, er + 1):
                        for j in range(c, ec + 1):
                            Seen.add((i, j))
        return res
