class Solution {
public:

    int Man(const vector<int>& L, const vector<int>& R)
    {
       return abs(L[0] - R[0]) + abs(L[1] - R[1]);
    }

    int minCostConnectPoints(vector<vector<int>> & points)
    {
        vector<pair<int, vector<int>>>  pq;
        vector<int> p0 = points[0];

        points.erase(points.begin());
        int res = 0;
        
        for (const vector<int> & p : points)
        {
            int dist = Man(p, p0);
            pq.push_back(make_pair(dist, p));
        }
        
        sort(pq.begin(), pq.end());
        
        while ( !pq.empty())
        {
            pair<int, vector<int>> p = pq.front();
            pq.erase(pq.begin());

            int dist;
            vector<int> coor;

            dist = p.first;
            coor = p.second;
            res += dist;

            int i = -1;            
            while (++i < pq.size())
            {
                pq[i].first = min(
                    pq[i].first, 
                    Man(pq[i].second, coor)
                );
            }
            sort(pq.begin(), pq.end());
        }
        return res;
    }
};

