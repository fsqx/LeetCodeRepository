#include <iostream>
#include <cstdlib>

using namespace std;
class Solution
{
public:
	bool isPalindrome(int x)
	{
		// 负数肯定不是回文数
		if (x < 0)
		{
			return false;
		}
		// 0结尾肯定不是回文数
		if (x % 10 == 0)
		{
			return false;
		}
		int oldX = x;
		// 翻转x
		long int resultNum = 0;
		int mod = 0;
		while (x != 0)
		{
			mod = x % 10;
			resultNum = resultNum * 10 + mod;
			x = x / 10;
		}
		if (oldX == resultNum)
		{
			return true;
		}
		return false;
	}
};