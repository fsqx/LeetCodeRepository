#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

extern int countNums(const vector<int> &nums, int targetNum, int index);
extern int binarySearch(const vector<int> &nums, int targetNum, int left, int right);

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int> > vectors = groupVectors(nums);
        sort(vectors.at(0).begin(), vectors.at(0).end(), [](int x, int y)
        {
            return x < y;
        });
        sort(vectors.at(1).begin(), vectors.at(1).end(), [](int x, int y)
        {
            return x < y;
        });
        //
    }

    vector<vector<int> > groupVectors(vector<int> &nums)
    {
        vector<int>::iterator iter = nums.begin();
        vector<vector<int> > vectors;

        // 将原数组按大于0 小于0 等于0 分成三组
        for(; iter != nums.end(); iter++)
        {
            if(*iter > 0)
            {
                vectors[0].push_back(*iter);
            }
            else if(*iter < 0)
            {
                vectors[1].push_back(*iter);
            }
            else
            {
                vectors[2].push_back(*iter);
            }
        }

        return vectors;
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