#include <iostream>
#include <cstdlib>

using namespace std;
class Solution
{
public:
	bool isPalindrome(int x)
	{
		// �����϶����ǻ�����
		if (x < 0)
		{
			return false;
		}
		// 0��β�϶����ǻ�����
		if (x % 10 == 0)
		{
			return false;
		}
		int oldX = x;
		// ��תx
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