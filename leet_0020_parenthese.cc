class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        if (!len)
            return true;
        if (len % 2)
            return false;

        // create map/dict: 1st way
        unordered_map<char, char>   M{ 
            {')', '('}, {'}', '{'}, {']', '['} };

        // create map/dict: 2nd way
        // unordered_map<char, char>   M
        // M['}'] = '{';
        // M[')'] = '(';
        // M[']'] = '[';

        deque<char> D;
        for (char c: s)
        {
            if (M.find(c) == M.end()) // case: left
                D.push_back(c);
            else // case: right
            {
                if ( !D.size() || D.back() != M[c])
                    return false;
                D.pop_back();
            }
        }
        if (D.size())
            return false;
        return true;
        
        
    }
};
