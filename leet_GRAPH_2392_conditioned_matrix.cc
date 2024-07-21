class Solution {
public:
    vector<vector<int>> buildMatrix(int k,
        vector<vector<int>>& rowConditions, 
        vector<vector<int>>& colConditions
    ){
        std::function<unordered_map<int, int>(vector<vector<int>>/*&*/)> TopoSort;
        TopoSort = [&](vector<vector<int>> /*&*/ conditions)
        {
            unordered_map<int, vector<int>> prev;
            vector<int> indegree(k, 0);
            for (auto p : conditions)
            {
                int before = p[0] - 1, after = p[1] - 1;
                prev[ before ].push_back( after );
                indegree[before] += 0;
                indegree[after] += 1;
            }
            unordered_map<int, int> res;
            vector<int> order;
            deque<int> Q;
            int i = -1;
            while (++i < k)
                if (indegree[i] == 0)
                    Q.push_back(i);
            while (!Q.empty())
            {
                int curr = Q.front();
                Q.pop_front();
                order.push_back(curr);
                for (int _next : prev[ curr ])
                {
                    indegree[_next]--;
                    if (indegree[_next] == 0)
                        Q.push_back(_next);
                }
            }
            // assert(order.size() == k);
            if (order.size() != k)
                throw std::runtime_error("");
            cout << order.size() << endl;
            i = -1;
            while (++i < order.size())
                res[order[i]] = i;
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
