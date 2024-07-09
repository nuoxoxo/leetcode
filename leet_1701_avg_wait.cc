class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        vector<double(*)(vector<vector<int>>& customers)> Solutions = {
            // My_simulation,
            My_simplified,
        };
        return Solutions[0](customers);
    }

    static double My_simplified(vector<vector<int>>& customers)
    {
        double N = customers.size();
        double W = 0;
        double elapse = customers[0][0];
        for (auto& p : customers)
        {
            if (p[0] > elapse)
                elapse = p[0];
            // elapse = max(p[0], elapse);
            W += p[1] + (elapse - p[0]);
            elapse += p[1];
        }
        return W / N;
    }

    static double My_simulation(vector<vector<int>>& customers)
    {
        double N = customers.size();
        double W = 0;
        double elapse = customers[0][0];
        for (auto& p : customers)
        {
            double wait;
            double overlap;
            if (elapse <= p[0])
            {
                wait = p[1];
                W += wait;
                elapse = p[0] + wait;
                // cout << "elp/ " << elapse << " wait/ " << wait << endl;
            }
            else
            {
                overlap = elapse - p[0];
                wait = p[1];
                W += overlap + wait;
                elapse += wait;
                // cout << "elp/ " << elapse << " olp/ " << overlap << " wait/ " << wait << endl;
            }
        }
        /*
        [[1,2],[2,5],[4,3]]     - doesnt matter if 0-index
        -.. 2
        --...... 1 overlap + 5 wait -> Can Derive:  tt-p[0]+p[1]
          ^
        ----....... 4 overlap + 3 wait -> Derive:   tt-p[0]+p[1]
            ^^^^


        [[2,3],[6,3],[7,5],[11,3],[15,2],[18,1]]
        --...
        ------...
        -------.......
        -----------......
        ---------------....
        ------------------.. 20

        */
        return W / N;
    }
};
