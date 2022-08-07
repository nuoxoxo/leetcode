

int minDistance(char * s1, char * s2){
    int r = (int) strlen(s1);
    int c = (int) strlen(s2);
    int **dp = malloc((r + 1) * sizeof(int*));
    if (!dp)
        exit(1);
    int i = -1, j;
    while (++i < r + 1)
        if (!(dp[i] = malloc((c + 1) * sizeof(int))))
            exit(1);
    i = -1;
    while (++i < r + 1)
    {
        j = -1;
        while (++j < c + 1)
            dp[i][j] = 0;
    }
    i = 0;
    while (++i < r + 1)
    {
        j = 0;
        while (++j < c + 1)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = dp[i - 1][j] > dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
        }
    }
    int res = r + c - 2 * dp[r][c];
    i = -1;
    while (++i < r + 1)
        free(dp[i]);
    free(dp);
    return res ;
}
