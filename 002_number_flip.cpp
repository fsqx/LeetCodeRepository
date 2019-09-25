#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
	int reverse(int x)
	{
		int flag = 1;

		if (x < 0)
		{
			flag = -1;
		}

		int resultNum = 0;

		while (x != 0)
		{
			int mod = x % 10;
			resultNum = resultNum * 10 + mod;
			x = x / 10;
		}
		return resultNum;
	}
};