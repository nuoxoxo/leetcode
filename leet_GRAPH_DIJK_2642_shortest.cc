class Graph {

vector<vector<pair<int /* dist, cost or weight */, int /* target, adjacency*/>>>    adj;

public:
    Graph(int n, vector<vector<int>>& edges)
    {
        int i = -1;
        while (++i < n)
            adj.push_back(vector<pair<int, int>>());
        for (auto e: edges)
        {
            int node = e[0];
            int dest = e[1];
            int cost = e[2];
            adj[node].push_back({cost, dest});
        }
    }
    
    void addEdge(vector<int> edge)
    {
        int node = edge[0];
        int dest = edge[1];
        int cost = edge[2];
        adj[node].push_back({cost, dest});
    }
    
    int shortestPath(int node1, int node2)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, node1});

        vector<int> D(adj.size(), -1); // -1 : unreachable nodes
        D[node1] = 0;

        while ( ! pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (node == node2)
                return dist;
            for (auto neig: adj[node])
            {
                int cost = neig.first;
                int idx = neig.second;
                // either uninitialized or a shorter path is found
                if (D[idx] == -1 || dist + cost < D[idx])
                {
                    D[idx] = dist + cost;
                    pq.push({ D[idx], idx });
                }
            }
        }
        return D[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
