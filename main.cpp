#include <iostream>
#include <cstdlib>
#include <vector>
//#include "001_two_sum.h"
//#include "007_number_flip.h"
//#include "009_number_of_tracts.h"
//#include "013_roman_to_interger.h"
//#include "014_Longest_Common_Prefix.h"
//#include "020_valid_parentheses.h"
//#include "021_merge_two_sorted_lists.h"
#include "026_remove_dumplicates_from_sorted_Array.h"

using namespace std;

int main()
{
    vector<int> nums(5, 0);
    nums[1] = 1;
    nums[2] = 1;
    nums[3] = 4;
    nums[4] = 4;
    Solution solution;
    cout << solution.removeDuplicates(nums) << endl;
    system("pause");
    return 0;
}