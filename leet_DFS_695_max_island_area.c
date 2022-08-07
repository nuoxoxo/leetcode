int	dfs(int **g, int r, int *c, int i, int j);

int	maxAreaOfIsland(int **grid, int r, int *c)
{
	int	res;
	int	i;
	int	j;
	int	temp;

	i = -1;
	res = 0;
	while (++i < r)
	{
		j = -1;
		while (++j < *c)
		{
			temp = dfs(grid, r, c, i, j);
			res = res > temp ? res : temp;
		}
	}
	return (res);
}

int	dfs(int **g, int R, int *C, int i, int j)
{
	int	l;
	int	u;
	int	d;
	int	r;

	if (i < 0 || j < 0 || i > R - 1 || j > *C - 1 || g[i][j] ^ 1)
		return (0);
	g[i][j] = 0;
	l = dfs(g, R, C, i - 1, j);
	u = dfs(g, R, C, i, j - 1);
	d = dfs(g, R, C, i, j + 1);
	r = dfs(g, R, C, i + 1, j);
	return (l + u + d + r + 1);
}
