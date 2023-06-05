class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coor)
    {
        int s = coor.size();
        if (s == 2)
            return true ;
        float   slope, temp;
        int     dx, dy, i;
        dx = coor[0][0] - coor[1][0];
        dy = coor[0][1] - coor[1][1];
        if (dx)
            slope = (float) dy / (float) dx;
        else
            slope = -1; // 1e9 works
        i = 1;
        while (++i < s)
        {
            dx = coor[i - 1][0] - coor[i][0];
            dy = coor[i - 1][1] - coor[i][1];
            temp = dx ? (float) dy / (float) dx : -1;
            if (slope != temp)
                return false ;
        }
        return true ;
    }
};

/*
[[2,1],[4,2],[6,3]]
[[0,0],[0,1],[0,-1]]
[[1,-8],[2,-3],[1,2]]
[[-4,-3],[1,0],[3,-1],[0,-1],[-5,2]]
*/
/*
[[2,1],[4,2],[6,3]]
[[0,0],[0,1],[0,-1]]
[[1,-8],[2,-3],[1,2]]
[[-4,-3],[1,0],[3,-1],[0,-1],[-5,2]]
*/
