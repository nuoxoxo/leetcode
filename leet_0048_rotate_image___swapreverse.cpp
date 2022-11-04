class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int n = matrix.size(), i = -1, j ;

        while (++i < n)
        {
            j = i - 1;
            while (++j < n)
                swap(matrix[i][j], matrix[j][i]) ;
            reverse(matrix[i].begin(), matrix[i].end());
            // print(matrix) ;
        }
    }

    void print(vector<vector<int>>& m)
    {
        int i = -1, j;
        while (++i < m.size())
        {
            j = -1;
            while (++j < m[0].size())
                cout << m[i][j] << ',';
            cout << endl;
        }
        cout << endl;
    }
};
