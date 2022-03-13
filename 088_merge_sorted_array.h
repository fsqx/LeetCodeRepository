#pragma once
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        vector<int> rstNum;
        int index = 0;
        int index1 = 0;
        int index2 = 0;

        for(; index1 < m || index2 < n;)
        {
            if(index1 >= m)
            {
                rstNum.push_back(nums2.at(index2));
                index2++;
            }
            else if(index2 >= n)
            {
                rstNum.push_back(nums1.at(index1));
                index1++;
            }
            else if(nums1.at(index1) < nums2.at(index2))
            {
                rstNum.push_back(nums1.at(index1));
                index1++;
            }
            else if(nums2.at(index2) <= nums1.at(index1))
            {
                rstNum.push_back(nums2.at(index2));
                index2++;
            }
        }

        nums1 = rstNum;
    }
};