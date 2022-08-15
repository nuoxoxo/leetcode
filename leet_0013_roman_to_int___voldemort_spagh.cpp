class Solution {
	public:

	int	romanToInt(string s)
	{
		int		res, len, i;
		char		c;

		len = (int) s.length();
		res = 0;
		i = 0;
		while (i < len)
		{
			c = s[i];
			if (c == 'V')
			{
				res += 5;
			}
			else if (c == 'L')
			{
				res += 50;
			}
			else if (c == 'D')
			{
				res += 500;
			}
			else if (c == 'M')
			{
				res += 1000;
			}
			else if (c == 'I' && i + 1 < len && s[i + 1] == 'V')
			{
				res += 4;
				i++;
			}
			else if (c == 'I' && i + 1 < len && s[i + 1] == 'X')
			{
				res += 9;
				i++;
			}
			else if (c == 'I')
			{
				res += 1;
			}
			else if (c == 'X' && i + 1 < len && s[i + 1] == 'L')
			{
				res += 40;
				i++;
			}
			else if (c == 'X' && i + 1 < len && s[i + 1] == 'C')
			{
				res += 90;
				i++;
			}
			else if (c == 'X')
			{
				res += 10;
			}
			else if (c == 'C' && i + 1 < len && s[i + 1] == 'D')
			
			{
				res += 400;
				i++;
			}
			else if (c == 'C' && i + 1 < len && s[i + 1] == 'M')
			{
				res += 900;
				i++;
			}
			else if (c == 'C')
			{
				res += 100;
			}
			i += 1;
		}
		return res;
	}
};
