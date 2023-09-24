"""

                1
            .5      .5 of prev
        .25     .5      .25
    .125    .625    .625    .125

                1
            1/2     1/2             (of prev)
        1/2     .5+.5   1/2         (of prev)
    1/2     .5+.5   .5+.5   1/2     (of prev)
1/2     .5+.5   .5+.5   .5+.5   1/2 (of prev)

"""
class Solution:
    def champagneTower(self, poured: int, query_row: int, query_glass: int) -> float:
        level = [ poured ]
        for n in range(1, query_row + 1):
            next_level = [0] * (n + 1)
            for i in range(n + 1):
                L = 0
                R = 0
                Loverflow = 0
                Roverflow = 0
                if i > 0:
                    L = level[i - 1]
                if i < len(level):
                    R = level[i]
                if L - 1 > 0:
                    Loverflow = L - 1
                if R - 1 > 0:
                    Roverflow = R - 1
                next_level[i] = Loverflow * .5 + Roverflow * .5
            level = next_level
        return min(1, level[query_glass])
