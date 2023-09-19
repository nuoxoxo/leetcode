  def minCostConnectPoints(self, points: List[List[int]]) -> int:
      def CalMan(L, R): # p1, p2
          return abs(L[0] - R[0]) + abs(L[1] - R[1])
      pq = []
      tt = 0
      p0 = points.pop(0) # 1 : we simply take the first element as our ref point
      for p in points:
          dist = CalMan(p0, p) 
          heapq.heappush(pq, [dist, p]) # 2 : push the dist btw P0 and Pi to heapQ
      while pq:
          dist, coor = heapq.heappop(pq)
          tt += dist # BFS : recap top of Q which has current minimal dist
          for p in pq: # HeapQ : update each elem ; update / heapify the Q
              p[0] = min(p[0], CalMan(p[1], coor))
          heapq.heapify(pq)
      return tt
