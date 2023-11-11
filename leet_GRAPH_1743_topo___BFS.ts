function restoreArray(adjacentPairs: number[][]): number[] {
    let D: { [key: number]: number[] } = {}
    let idg: { [key: number]: number } = {}
    for (const pair of adjacentPairs) {
      const [a, b] = pair
      D[a] = D[a] || []
      D[b] = D[b] || []
      D[a].push(b)
      D[b].push(a)
      idg[a] = (idg[a] || 0) + 1
      idg[b] = (idg[b] || 0) + 1
    }
    let size = adjacentPairs.length + 1
    let res: number[] = []
    let isFound = false
    let head: number, tail: number
    for (let [k, v] of Object.entries(idg)) {
      let key = parseInt(k, 10)
      if (v === 1) {
        if (isFound) {
          tail = key
          break
        } else {
          isFound = true
          head = key
        }
      }
    }
    let dq: number[] = []
    dq.push(head)
    while (dq.length > 0) {
      let node = dq.shift() as number
      res.push(node)
      for (let n of D[node]) {
        idg[n]--
        if (idg[n] === 1) {
          dq.push(n)
        }
      }
    }
    res.push(tail)
    return res
};
