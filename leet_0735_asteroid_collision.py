class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        Q = []
        """for a in asteroids:
            big = a
            while Q and big * Q[-1] < 0:
                big = None
                if abs(big) > abs(Q[-1]):
                    big = a
                elif abs(big) < abs(Q[-1]):
                    big = Q[-1]
                print(Q, big, 'in')
                Q.pop()
            if big != None:
                Q.append(big)
            print(Q, big, 'out')
        """
        i = 0
        a = asteroids
        while i < len(a):
            if not Q or a[i] > -1 or Q[-1] < 0:
                Q.append(a[i])
                i += 1
            elif a[i] + Q[-1] < 0:
                Q.pop()
                # i -= 1
            elif a[i] + Q[-1] == 0:
                i += 1
                Q.pop()
            else:
                i += 1
            # i += 1
        return Q

