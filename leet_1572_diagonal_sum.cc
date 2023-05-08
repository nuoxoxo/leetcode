class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int len = (int) mat.size();
        int i = -1;
        int res = 0;
        while (++i < len)
            res += mat[i][i] + mat[i][len - i - 1];
        if (len % 2)
            res -= mat[len / 2][len / 2];
        return res;
    }
};
