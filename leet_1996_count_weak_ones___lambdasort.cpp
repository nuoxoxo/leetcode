class Solution {
public:
    #define vvi vector<vector<int>>
    #define vi vector<int>
    int numberOfWeakCharacters(vector<vector<int>>& properties)
    {
        int     res = 0;
        int     top = -1;

        sort(properties.begin(), properties.end(),
             [](const vi& a, const vi& b) -> bool
             {
                 if (a[0] == b[0])
                     return a[1] < b[1];
                 return a[0] > b[0];
             });
        int i = -1;
        while (++i < properties.size())
        {
            if (properties[i][1] < top)
                res++;
            else
                top = properties[i][1];
        }
        return res;
    }
};
