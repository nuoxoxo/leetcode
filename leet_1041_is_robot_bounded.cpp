class Solution {
public:
    bool isRobotBounded(string s)
    {
        vector<int> P = {0,0};
        vector<int> D = {0,1};
        int         i = -1;

        while (++i < s.length())
        {
            if (s[i] == 'L')	swap(D[0], D[1]), D[0] *= -1;
            if (s[i] == 'R')	swap(D[0], D[1]), D[1] *= -1;
            if (s[i] == 'G')	P[0] += D[0], P[1] += D[1];
        }

        return ((P[0] == 0 && P[1] == 0) || (D[0] != 0 || D[1] != 1));
    }
};
