#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

extern int countNums(const vector<int> &nums, int targetNum, int index);
extern int binarySearch(const vector<int> &nums, int targetNum, int left, int right);

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        //双指针
        if(nums.size() < 3)
        {
            return vector<vector<int> >();
        }

        sort(nums.begin(), nums.end(), [](int x, int y)
        {
            return x < y;
        });
        vector<vector<int> > rstVector;
        int rstLeft = 0;
        int rstRight = nums.size() - 1;

        for(int i = 0; i < nums.size() - 2; i++)
        {
            if(nums.at(i) > 0)
            {
                break;
            }

            int left = i + 1;
            int right = rstRight;

            while(left < right)
            {
                if(nums.at(i) + nums.at(left) + nums.at(right) == 0)
                {
                    rstVector.push_back(vector<int>({ nums.at(i), nums.at(left), nums.at(right) }));

                    while(left < right && nums.at(left) == nums.at(left + 1))
                    {
                        left++;
                    }

                    while(left < right && nums.at(right) == nums.at(right - 1))
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                else
                {
                    if(nums.at(left) + nums.at(right) + nums.at(i) > 0)
                    {
                        right--;
                    }
                    else if(nums.at(left) + nums.at(right) + nums.at(i) < 0)
                    {
                        left++;
                    }
                }
            }
        }

        set<vector<int> > s(rstVector.begin(), rstVector.end());
        rstVector.assign(s.begin(), s.end());
        return rstVector;
#if 0

        // 暴力算法。时间太长。
        if(nums.size() < 3)
        {
            return vector<vector<int> >();
        }

        sort(nums.begin(), nums.end(), [](int x, int y)
        {
            return x < y;
        });
        vector<vector<int> > rstVector;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums.at(i) > 0)
            {
                break;
            }

            for(int k = i + 1; k < nums.size(); k++)
            {
                int addNum;

                if(nums.at(i) == 0 && nums.at(k) == 0)
                {
                    if(search(nums, 0, k + 1, nums.size() - 1) != -1)
                    {
                        rstVector.push_back(vector<int>({ 0, 0, 0 }));
                    }

                    break;
                }
                else
                {
                    addNum = nums.at(i) + nums.at(k);
                }

                if(addNum >= 0)
                {
                    break;
                }

                int rst = search(nums, -addNum, k + 1, nums.size() - 1);

                if(rst == -1)
                {
                    continue;
                }
                else
                {
                    //rstVector.push_back(vector<int>({ nums.at(i), nums.at(k), nums.at(rst) }));
                }
            }
        }

        set<vector<int> > s(rstVector.begin(), rstVector.end());
        rstVector.assign(s.begin(), s.end());
        return rstVector;
#endif
    }

    // 普通二分法查找
    int search(vector<int>& nums, int target, int left, int right)
    {
        while(left <= right)
        {
            int mid = (right - left) / 2 + left;

            if(nums.at(mid) > target)
            {
                right = mid - 1;
            }
            else if(nums.at(mid) < target)
            {
                left = mid + 1;
            }
            else
            {
                return mid;
            }
        }

        return -1;
    }
};


int countNums(const vector<int> &nums, int targetNum, int index)
{
    int count = 1;
    int tmpIndex = index - 1;

    while(tmpIndex >= 0 && nums.at(tmpIndex) == targetNum)
    {
        tmpIndex--;
        count++;
    }

    tmpIndex = index + 1;

    while(nums.size() > tmpIndex && nums.at(tmpIndex) == targetNum)
    {
        tmpIndex++;
        count++;
    }

    return count;
}

int binarySearch(const vector<int> &nums, int targetNum, int left, int right)
{
    if(left == right)
    {
        if(nums.at(left) == targetNum)
        {
            cout << "index: " << left << endl;
            return countNums(nums, targetNum, left);
        }

        return 0;
    }

    int vctLength = right - left + 1;
    int mid = vctLength / 2 + left;

    if(nums.at(mid) > targetNum)
    {
        return binarySearch(nums, targetNum, left, mid - 1);
    }
    else if(nums.at(mid) < targetNum)
    {
        return binarySearch(nums, targetNum, mid + 1, right);
    }
    else if(nums.at(mid) == targetNum)
    {
        cout << "index: " << mid << endl;
        return countNums(nums, targetNum, mid);
    }
}