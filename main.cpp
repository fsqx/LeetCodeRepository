#include <iostream>
#include <cstdlib>
#include "021_merge_two_sorted_lists.h"

using namespace std;

int main()
{
    ListNode one(1);
    ListNode two(2);
    ListNode three(3);
    one.next = &two;
    two.next = &three;
    ListNode four(1);
    ListNode five(3);
    ListNode six(4);
    four.next = &five;
    five.next = &six;
    Solution solution;
    solution.mergeTwoLists(&one, &four);
    system("pause");
    return 0;
}