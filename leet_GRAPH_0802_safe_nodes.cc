class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<vector<int>> parentsof(N, vector<int>());
        vector<int> childrensizeof(N, -1);
        deque<int> Q;
        vector<int> terms;
        int node = -1;
        while (++node < N){
            auto children = graph[node];
            for (int child: children)
                parentsof[child].push_back(node);
            int len = children.size();
            childrensizeof[node] = len;
            if (!len){
                terms.push_back(node);
                Q.push_back(node);
            }
        }
        while (!Q.empty()){
            int node = Q.front();
            Q.pop_front();
            for (int parent: parentsof[node]){
                --childrensizeof[parent];
                if (!childrensizeof[parent]){
                    terms.push_back(parent);
                    Q.push_back(parent);
                }
            }
        }
        sort(terms.begin(), terms.end());
        return terms;
    }
};
