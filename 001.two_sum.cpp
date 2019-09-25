#include <vector>
using namespace std;
class Solution
{
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		int index_a = -1;
		int index_b = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			int aim = target - nums.at(i);
			index_b = vectorHasAimNumber(nums, aim, i);
			if (index_b != -1)
			{
				vector<int> result;
				result.push_back(i);
				result.push_back(index_b);
				return result;
			}
		}
		return vector<int>();
	}

	int vectorHasAimNumber(vector<int>& nums, int target, int index)
	{
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums.at(i) == target && i != index)
			{
				return i;
			}
		}
		return -1;
	}
};