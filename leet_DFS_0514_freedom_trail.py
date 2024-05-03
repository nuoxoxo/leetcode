class Solution:
    def findRotateSteps(self, ring: str, key: str) -> int:
        return [
            self.dfs_using_lru_cache,
            self.dfs_using_DIY_cache,
            self.BFS, # slow
        ][0](ring, key)

    def BFS(self, ring: str, key: str) -> int:
        ringsize, keysize = len(ring), len(key)
        start = (0, 0, 0)
        Q = deque()
        Q.append(start)
        seen = set()
        seen.add((0, 0))
        while Q:
            iring, ikey, steps = Q.popleft()
            if ikey == keysize:
                return steps
            if ring[iring] == key[ikey]:
                nxt = (iring, ikey + 1, steps + 1)
                Q.append(nxt)
                continue
            L = (iring - 1) % ringsize
            R = (iring + 1) % ringsize
            if (L, ikey) not in seen:
                Q.append((L, ikey, steps + 1))
                seen.add((L, ikey))
            if (R, ikey) not in seen:
                Q.append((R, ikey, steps + 1))
                seen.add((R, ikey))
        assert False

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

