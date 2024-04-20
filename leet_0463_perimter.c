typedef int (* functions) (int **, int, int*);

int Math(int **, int, int *);
int BruteForce_Iterative(int **, int, int *);
int BruteForce_Iterative_Alt(int **, int, int *);

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {

    functions Solutions [] = {
        Math,
        BruteForce_Iterative,
        BruteForce_Iterative_Alt,
    };
    return Solutions[0]((int**) grid, gridSize, (int*) gridColSize);
}

int Math(int** grid, int gridSize, int* gridColSize) {
    int R = gridSize, C = *gridColSize;
    int res = 0;
    int r = -1, c;
    while (++r < R)
    {
        c = -1;
        while (++c < C)
        {
            if (grid[r][c] == 1)
            {
                res += 4;
                if (r > 0 && grid[r - 1][c] == 1)
                    res -= 2;
                if (c > 0 && grid[r][c - 1] == 1)
                    res -= 2;
            }
        }
    }
    return res;
}

int BruteForce_Iterative(int** G, int gridSize, int* gridColSize) {

    int dr[4] = {1,0,-1, 0};
    int dc[4] = {0,1, 0,-1};
    int R = gridSize;
    int C = *gridColSize;
    int res = 0;
    int r = -1, c;
    while (++r < R) {
        c = -1;
        while (++c < C) {
            if (G[r][c]) {
                int i = -1;
                while (++i < 4) {
                    int rr = r + dr[i];
                    int cc = c + dc[i];
                    if (rr == R || rr < 0 || cc == C || cc < 0 || !G[rr][cc])
                        ++res;
                }
            }
        }
    }
    return res;
}

int countNeighbors(int**, int, int*, int, int);
int hasOneNeighbor(int**, int, int*, int, int);
int BruteForce_Iterative_Alt(int** G, int gridSize, int* gridColSize) {

    int R = gridSize, C = *gridColSize;
    int res = 0;
    int r = -1, c;
    while (++r < R) {
        c = -1;
        while (++c < C) {
            if (G[r][c] == 1)
                res += countNeighbors(G, gridSize, gridColSize, r, c);
        }
    }
    return res;
}

int hasOneNeighbor(int** G, int gridSize, int* gridColSize, int r, int c) {

    int R = gridSize, C = *gridColSize;
    if (r == R || r < 0 || c == C || c < 0 || G[r][c] == 0)
        return 0;
    return 1;
}

int countNeighbors(int** G, int gridSize, int* gridColSize, int r, int c) {

    int neigs = hasOneNeighbor(G, gridSize, gridColSize, r + 1, c) \
        + hasOneNeighbor(G, gridSize, gridColSize, r - 1, c) \
        + hasOneNeighbor(G, gridSize, gridColSize, r, c + 1) \
        + hasOneNeighbor(G, gridSize, gridColSize, r, c - 1);
    return 4 - neigs;
};

