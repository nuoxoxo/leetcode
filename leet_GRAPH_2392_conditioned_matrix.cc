/*
// testcase
8
[[1,2],[7,3],[4,3],[5,8],[7,8],[8,2],[5,8],[3,2],[1,3],[7,6],[4,3],[7,4],[4,8],[7,3],[7,5]]
[[5,7],[2,7],[4,3],[6,7],[4,3],[2,3],[6,2]]
*/

class Solution {
public:
    static vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions)
    {
        vector<vector<vector<int>>(*)(int, vector<vector<int>>&, vector<vector<int>>&)> solutions = {
            TopoSort_returns_a_list,
            // TopoSort_returns_an_index_map,
        };
        return solutions[0](k, rowConditions, colConditions);
    }
    
    static vector<vector<int>> TopoSort_returns_a_list(int k,
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

        std::function<vector<int>/*unordered_map<int, int>*/(vector<vector<int>>/*&*/)> TopoSort;
        TopoSort = [&](vector<vector<int>> /*&*/ conditions)
        {
            unordered_map<int, vector<int>> goingto;
            vector<int> indegree(k, 0);

            // Toposort 1/
            //  -> compute the in-degree for each vertex
            //  indegree/ number of incoming edges
            for (auto p : conditions)
            {
                int src = p[0] - 1, des = p[1] - 1;
                goingto[ src ].push_back( des );
                indegree[src] = indegree[src] ? indegree[src] : 0;
                indegree[des] += 1;
            }

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
                for (int _next : goingto[ curr ]) // decrease indegree by 1
                {
                    indegree[_next]--;
                    if (indegree[_next] == 0) // add U to Q once indegree == 0
                        Q.push_back(_next);
                }
                ordering.push_back(curr); // add U to to topolocial ordering
            }

            if (ordering.size() != k)
                throw std::runtime_error("");

            // DBG
            cout << "\nsize/ " << ordering.size();
            cout << "\ntopologial ordering/";
            for (int _ : ordering) cout << _ << ' ';

            return ordering;
        };

        try {
            vector<int> Rows = TopoSort(rowConditions);
            vector<int> Cols = TopoSort(colConditions);
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
            {
                int rindex = distance(begin(Rows), find(begin(Rows), end(Rows), i));
                assert (rindex != Rows.size());
                int cindex = distance(begin(Cols), find(begin(Cols), end(Cols), i));
                assert (cindex != Cols.size());
                res[ rindex ][ cindex ] = i + 1;
            }
            return res;

        } catch (const std::runtime_error /*std::exception*/ & e) {

            return vector<vector<int>>{};
        }
    }

    static vector<vector<int>> TopoSort_returns_an_index_map(int k,
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
            unordered_map<int, vector<int>> goingto;
            vector<int> indegree(k, 0);

            // Toposort 1/
            //  -> compute the in-degree for each vertex
            //  indegree/ number of incoming edges
            for (auto p : conditions)
            {
                int src = p[0] - 1, des = p[1] - 1;
                goingto[ src ].push_back( des );
                indegree[src] = indegree[src] ? indegree[src] : 0;
                indegree[des] += 1;
            }

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
                for (int _next : goingto[ curr ]) // decrease indegree by 1
                {
                    indegree[_next]--;
                    if (indegree[_next] == 0) // add U to Q once indegree == 0
                        Q.push_back(_next);
                }
                ordering.push_back(curr); // add U to to topolocial ordering
            }

            unordered_map<int, int> index_dict;
            if (ordering.size() != k)
                throw std::runtime_error("");
            cout << "\nsize/ " << ordering.size();
            i = -1;
            while (++i < ordering.size())
                index_dict[ordering[i]] = i;
            cout << "\ntopologial ordering/";
            for (int _ : ordering) cout << _ << ' ';
            return index_dict;
        };

        try {
            unordered_map<int, int> row_index = TopoSort(rowConditions);
            unordered_map<int, int> col_index = TopoSort(colConditions);
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
                res[ row_index[i] ][ col_index[i] ] = i + 1;
            return res;

        } catch (const std::runtime_error /*std::exception*/ & e) {

            return vector<vector<int>>{};
        }
    }

};
