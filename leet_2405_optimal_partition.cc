class Solution {
public:
      int partitionString(string s) 
    {
       int i = -1;
       int count = 0;
       set<char> S;

       while (++i < s.length())
       {
           if (S.find(s[i]) != S.end())
           {
               ++count;
               S.clear();
           }
           S.insert(s[i]);
       }
       return count + 1;
    }
};
