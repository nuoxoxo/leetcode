class Solution {
public:
    vector<vector<int>> buildMatrix(int k,
        vector<vector<int>>& rowConditions, 
        vector<vector<int>>& colConditions
    ){

        /*
        row/ [1,2],[3,2]
            -> 1 above 2, 3 above 2
            -> graph/ 1-> 2 <-3

        col/ [2,1],[3,2]
            -> graph/ 3 -> 2 -> 1

            === Toposort ===
        def/goal: sort vertices such that for every directed edge
            u -> v
        vertex u should always come before vertex v in the ordering


        */


        std::function<unordered_map<int, int>(vector<vector<int>>/*&*/)> TopoSort;
        TopoSort = [&](vector<vector<int>> /*&*/ conditions)
        {
            unordered_map<int, vector<int>> prev;
            vector<int> indegree(k, 0);

            // Toposort 1/
            //  -> compute the in-degree for each vertex
            //  indegree/ number of incoming edges
            for (auto p : conditions)
            {
                int before = p[0] - 1, after = p[1] - 1;
                prev[ before ].push_back( after );
                indegree[before] = indegree[before] ? indegree[before] : 0;
                indegree[after] += 1;
            }

            unordered_map<int, int> res;
            vector<int> ordering;
            deque<int> Q;
            int i = -1;

            // Toposort 2/
            //  -> all 0-indegree vertices gathered in a queue
            while (++i < k)
                if (indegree[i] == 0)
                    Q.push_back(i);

            // Toposort 3/
            //
            //  pop a U (vertex) from Q/
            //      -> add U to topo "ordering"
            //      -> for every V of u, dec. V's indegree by 1
            //      -> add V to Q if V becomes 0
            while (!Q.empty())
            {
                int curr = Q.front();
                Q.pop_front();
                for (int _next : prev[ curr ]) // decrease indegree by 1
                {
                    indegree[_next]--;
                    if (indegree[_next] == 0) // add U to Q once indegree == 0
                        Q.push_back(_next);
                }
                ordering.push_back(curr); // add U to to topolocial ordering
            }

            if (ordering.size() != k)
                throw std::runtime_error("");
            cout << "\nsize/ " << ordering.size();
            i = -1;
            while (++i < ordering.size())
                res[ordering[i]] = i;
            cout << "\ntopologial ordering/";
            for (int _ : ordering) cout << _ << ' ';
            return res;
        };

        try {
            unordered_map<int, int> Rows = TopoSort(rowConditions);
            unordered_map<int, int> Cols = TopoSort(colConditions);
            ///     DBG
            /*
            for (auto p : Rows)
                cout << p.first << ':' << p.second << endl;
            cout << endl;
            for (auto p : Cols)
                cout << p.first << ':' << p.second << endl;
            */
            vector<vector<int>> res(k, vector<int>(k, 0));
            int i = -1;
            while (++i < k)
                res[ Rows[i] ][ Cols[i] ] = i + 1;
            return res;

        } catch (const std::runtime_error /*std::exception*/ & e) {

            return vector<vector<int>>{};
        }
    }
};
