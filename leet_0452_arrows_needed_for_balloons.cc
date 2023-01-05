class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& P){
        int Df, De;

        int L = (int) P.size();
        sort(P.begin(), P.end());
        int Uf = P[0][0];
        int Ue = P[0][1];
        int i = 0;
        int count = 1;
        while (++i < L)
        {
            Df = P[i][0];
            De = P[i][1];
            if (Df <= Ue)
            {
                Uf = max(Uf, Df);// ? Uf : Df;
                Ue = min(Ue, De);// ? Ue : De;
            }
            else
            {
                Uf = Df;
                Ue = De;
                count ++;
            }
        }
        return count ;
    }
};
