class Solution:
    def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
        return [
            Rerooting,
        ][0](n, edges)

def Rerooting(N: int, edges: List[List[int]]) -> List[int]:
    ADJ = defaultdict(list)
    for u, v in edges:
        ADJ[u].append(v)
        ADJ[v].append(u)
    # when node(idx) is root, how many nodes the subtree contains w/o going up to the parent
    subtree = [0] * N
    dists = [0] * N
    def info(node, parent):
        subtree[node] = 1
        dists[node] = 0
        for v in ADJ[node]:
            if v != parent:
                info(v, node)
                subtree[node] += subtree[v]
                dists[node] += dists[v] + subtree[v]
    res = [-1] * N
    info(0, -1)
    res[0] = dists[0]
    # print('distances/', dists)
    # print('subtree/', subtree)
    # parent_nodes -> how many nodes from other side of parent
    # parent_dists -> total distances from other side of parent
    def reroot(node, parent, parent_nodes, parent_dists):
        for v in ADJ[node]:
            if v != parent:
                other_nodes = subtree[node] - subtree[v] + parent_nodes
                other_dists = dists[node] - (dists[v] + subtree[v]) + parent_nodes + parent_dists
                res[v] = other_dists + other_nodes + dists[v]
                reroot(v, node, other_nodes, other_dists)
    reroot(0, -1, 0, 0)
    return res

