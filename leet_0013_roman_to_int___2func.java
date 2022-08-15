class Solution {

    public int romanToInt(String s)
	{
		int len = s.length();
		int res = 0;
		int i = 0;
		int self, next;

		while (i < len)
		{
			self = bf(s.charAt(i));
			next = i + 1 < len ? bf(s.charAt(i + 1)) : 0;  
			if (self < next) 
			{
				res += next - self;
				i++;
			}
			else
			{
				res += self;
			}
			i++;
		}
		return res;
	}

	public int bf(char c) // brute-f'ing_forcez
	{
		if (c == 'I')
			return 1;
		if (c == 'V')
			return 5;
		if (c == 'X')
			return 10;
		if (c == 'L')
			return 50;
		if (c == 'C')
			return 100;
		if (c == 'D')
			return 500;
		if (c == 'M')
			return 1000;
		else
			return 0;
	}
}
