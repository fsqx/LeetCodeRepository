
#include "mainHead.h"

int main()
{
#if 0
	vector<int> nums(5, 0);
	nums[1] = 1;
	nums[2] = 1;
	nums[3] = 4;
	nums[4] = 4;
	Solution solution;
	cout << solution.removeDuplicates(nums) << endl;
#endif
	string ss = "abcabcbb";
	Solution solution;
	solution.lengthOfLongestSubstring(ss);

	system("pause");
	return 0;
}