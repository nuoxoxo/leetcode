class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        N = len( beginWord )
        Seen = set([beginWord])
        Q = deque([(beginWord, 1)])
        D = defaultdict(list)
        for w in wordList:
            assert N == len(w)
            for i in range(N):
                possible = w[:i] + '@' + w[i + 1:]
                D[ possible ].append(w)
        while Q:
            w, lv = Q.popleft()
            for i in range(N):
                possible = w[:i] + '@' + w[i + 1:]
                # print(endWord, D[possible])
                if endWord in D[ possible ]:
                    return lv + 1
                for candidate in D[possible]:
                    if candidate not in Seen:
                        Q.append((candidate, lv + 1))
                        Seen.add(candidate)
        # assert False
        return 0

"""
"hit" -> ["hot","dot","dog","lot","log","cog"] -> "cog"
        
        hit ............. lv.1
   /     |     \
@it     h@t     hi@ ..... lv.2
/|\     /|\     /|\
** *   * * *   * * *
-> '@i@' is not possible
-> hence 'h@t' is left
        /|\
    @ot h@t ho@ ......... lv.3
        \|/
        hot
"""
