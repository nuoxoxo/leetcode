class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        return [
            self.dfs_using_lru_cache,
            self.dfs_using_DIY_cache,
        ][0](ring, key)

    def dfs_using_DIY_cache(self, ring: str, key: str) -> int:
        # match each char in RING to its index(es) which can be several
        ringsize, keysize = len(ring), len(key)

        has_cache = [[False for _ in range(keysize)] for _ in range(ringsize)]
        cache = [[None for _ in range(keysize)] for _ in range(ringsize)]

        D = defaultdict(list)
        for i, c in enumerate(ring):
            D[c].append(i)
        res = 0
        def Go(iring, ikey) -> int:
            if ikey == keysize:
                return 0

            if has_cache[iring][ikey]:
                return cache[iring][ikey]

            res = 10 ** 20
            char = key[ikey]
            for nxt in D[char]:

                # 1 - align current char in key
                # clockwise/anticlockwise on 1st direction
                R = abs(iring - nxt)
                # clockwise/anticlockwise on the other direction
                L = ringsize - R
                curr_best = min(L, R) + 1

                # 2 - align next char in key
                next_best = Go (nxt, ikey + 1)
                tt = curr_best + next_best
                res = min(res, tt)
            has_cache[iring][ikey] = True
            cache[iring][ikey] = res
            return res
        return Go(0, 0)

    def dfs_using_lru_cache(self, ring: str, key: str) -> int:
        # match each char in RING to its index(es) which can be several
        ringsize, keysize = len(ring), len(key)
        D = defaultdict(list)
        for i, c in enumerate(ring):
            D[c].append(i)
        res = 0
        @lru_cache
        def Go(iring, ikey) -> int:
            if ikey == keysize:
                return 0
            res = 10 ** 20
            char = key[ikey]
            for nxt in D[char]:

                # 1 - align current char in key
                # clockwise/anticlockwise on 1st direction
                R = abs(iring - nxt)
                # clockwise/anticlockwise on the other direction
                L = ringsize - R
                curr_best = min(L, R) + 1

                # 2 - align next char in key
                next_best = Go (nxt, ikey + 1)
                tt = curr_best + next_best
                res = min(res, tt)
            return res
        return Go(0, 0)

