class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = (int) isConnected.size();
             
        int res = 0;
        int i = -1;
        
        while (++i < n)
        {
            if (isConnected[i][i] ^ 1)
                continue ;

            deque<int>  dq;
            dq.push_back(i);
            
            while (!dq.empty())
            {
                int     node = dq.front();
                int     j = -1;

                dq.pop_front();                
                isConnected[node][node] = 2;
                while (++j < n)
                {
                    if (isConnected[node][j]==1)
                    {
                        dq.push_back(j);
                        isConnected[node][j] = 2;
                        isConnected[j][node] = 2;
                    }                    
                }
            }
            ++res;
        }
            
        return (res);
    }
};;
