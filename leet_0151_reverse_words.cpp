class Solution {
public:
    string reverseWords(string s)
    {
        vector<string>      arr;
        stringstream        ss(s);
        string              res, tmp;
        int                 i, n;
        
        while (ss >> tmp)
            arr.push_back(tmp);
        reverse(arr.begin(), arr.end());
        n = arr.size();
        i = -1;
        while (++i < n)
        {
            res += arr[i];
            if (i != n - 1)
                res += ' ';
        }
        return res ;
    }
};
