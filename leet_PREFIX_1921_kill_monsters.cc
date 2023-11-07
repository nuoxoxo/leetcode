class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed)
    {
        vector<int> T;
        int len = (int) dist.size();
        int i = -1;
        while (++i < len)
            T.push_back((dist[i] + speed[i] - 1) / speed[i]);
        sort(T.begin(), T.end());
        int res = 0;
        for (int & t : T)
        {
            if (res == t)
                break ;
            res++;
        }
        return res;
    }
};
