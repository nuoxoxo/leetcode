class Solution {
public:
      int partitionString(string s) 
    {
       int i = -1;
       int count = 0;
       unordered_map<char,bool> mp;

       while (++i < s.length())
       {
           if (mp.find(s[i]) != mp.end())
           {
                count++;
                mp.clear();
           }  
           mp[s[i]]=true; 	  
       }
       return count + 1;
    }
};
