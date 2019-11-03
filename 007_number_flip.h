#include <iostream>
#include <cstdlib>

using namespace std;

class Solution007
{
public:
	int reverse(int x)
	{
		long int resultNum = 0;
		int mod = 0;
		while (x != 0)
		{
			mod = x % 10;
			resultNum = resultNum * 10 + mod;
			x = x / 10;
		}

		if (resultNum < -2147483648 || resultNum > 2147483647)
		{
			return 0;
		}

		return static_cast<int>(resultNum);
	}
};