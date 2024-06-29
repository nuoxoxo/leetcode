class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &E /*edges*/)
    {
        /*
        [0,3],[0,4],
        [1,3],
        [2,4],[2,7],
        [3,5],[3,6],[3,7],
        [4,6]

        - look at all 2nd-positions: 0, 1, 2 have no ancestors
        - from (0,3) (1,3) we know 3 has two: 0, 1
        - from (0,4) (2,4) we know 4 has two: 0, 2
        - but these having direct ancestors are coincident
        - for eg. 5 has 3 ancestors:
            - degree-1 ---> 3
            - degree-2 ---> 0,1
            - we can think this way: [5]--1-->[3](0,1) so 1+2
        - 6 has 5 ancestors:
            - degree-1 ---> 3,4
            - degree-2 ---> 0,1,2
            - we can think this way:
                - [6]--1-->[3](0,1)
                - [6]--1-->[4](0,2) so a set(3,4,0,1,2)
        - 7 has 4:
            - [7]--1-->[2]
            - [7]--1-->[3](0,1) so a set(2,3,0,1)
        */

        #define vi vector<int>
        // #define si unordered_set<int> // BUG
        #define si set<int>

        // for each child of someone, save its direct parent
        vector<vi> ADJ(n, vi{});
        for (auto e : E)
        {
            int src = e[0], des = e[1];
            ADJ[ des ].push_back( src );
        }

        // def. DFS
        std::function<void(int, si &, si &)> DFS;
        DFS = [&](int node, si & SEEN, si & path){
            if (SEEN.find(node) == end(SEEN))
            {
                SEEN.insert(node);
                path.insert(node);
                for (int next: ADJ[node])
                {
                    if (SEEN.find(next) == end(SEEN))
                        DFS(next, SEEN, path);
                }
            }
        };

        // DFS - get to the bottom of each nodev ~ [0,n-1]
        int node = -1;
        vector<vi> res;
        while (++node < n)
        {
            si SEEN;
            si parents;
            for (int parent : ADJ[node])
            {
                if (SEEN.find(parent) == end(SEEN))
                    DFS(parent, SEEN, parents);
            }
            // for (int parent : parents)
                // temp.push_back(parent);
            res.push_back(vector<int>(begin(parents), end(parents)));
        }
        return res;
    }
};
