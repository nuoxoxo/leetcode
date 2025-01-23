class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r,c,R,C,n,i;
        R = mat.size();
        C = mat[0].size();
        unordered_map<int,int> rows,cols, rowcount,colcount;
        r = -1;
        while (++r < R){
            c = -1;
            while (++c < C){
                n = mat[r][c];
                rows[n] = r;
                cols[n] = c;
            }
        }
        i = -1;
        while (++i < arr.size()){
            n = arr[i];
            r = rows[n];
            rowcount[r]++;
            if (rowcount[r] == C)
                break ;
            c = cols[n];
            colcount[c]++;
            if (colcount[c] == R)
                break ;
        }
        assert (i ^ -1);
        return i;
    }
};
