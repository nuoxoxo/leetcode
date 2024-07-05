class Solution {

class UnionFind {
private:
    vector<int> parents;
public:
    UnionFind(int N)
    {
        this->parents.resize( N );
        int i = -1;
        while (++i < N)
            this->parents[i] = i;
    }

    int Find(int node)
    {
        if (this->parents[node] != node)
            this->parents[node] = this->Find(this->parents[node]);
        return this->parents[node];
    }

    void UnionSets(int L, int R)
    {
        int lu = this->Find(L), ru = this->Find(R);
        if (lu != ru)
            this->parents[lu] = ru;
    }

    bool IsConnected(int L, int R) { return this->Find(L) == this->Find(R); }
};

public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges)
    {
        int res = 0;
        UnionFind *Alice = new UnionFind(n), * Bob = new UnionFind(n);

        for (auto e : edges)
        {
            int t = e[0], u = e[1], v = e[2];
            u--;
            v--;
            if (t == 3)
            {
                if (Alice->IsConnected(u, v))
                    res++;
                else
                {
                    Alice->UnionSets(u, v);
                    Bob->UnionSets(u, v);
                }
            }
        }
        for (auto e : edges)
        {
            int t = e[0], u = e[1], v = e[2];
            u--;
            v--;
            UnionFind * curr = nullptr;
            if (t == 1)
                curr = Alice;
            else if (t == 2)
                curr = Bob;
            else if (t == 3)
                continue ;
            if (curr->IsConnected(u, v))
                res++;
            else
                curr->UnionSets(u, v);
        }
        int i = -1;
        while (++i < n)
        {
            if ( ! Alice->IsConnected(0, i) || ! Bob->IsConnected(0, i))
            {
                delete Alice;
                delete Bob;

                return -1;
            }
        }
        delete Alice;
        delete Bob;

        return res;
    }
};
