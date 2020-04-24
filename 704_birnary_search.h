#ifndef _BIRNARY_SEARCH_HPP_
#define _BIRNARY_SEARCH_HPP_
#include <iostream>
#include <vector>

using namespace std;

/**
 * �������ұ߽�Ķ��ַ����ң��ص�������ȷ�������䣬
 * �����ҵ�Ԫ��ʱ����ֱ�ӷ���Ԫ�ص����������ǽ���λ����Ϊ���ұ߽磬ֱ����������Ϊ��
 * ���ַ�����Ӧ�����Ƿ�Խ�磬������������ַ�����ʱ
 */

class BirnarySearch
{
public:
    // ��ͨ���ַ�����
    int search(vector<int>& nums, int target)
    {
        int length = nums.size();
        int left = 0;
        int right = length - 1;

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

    // ������߽�Ķ��ַ����� TODO
    int searchLeft(vector<int>& nums, int target)
    {
        int length = nums.size();
        int left = 0;
        int right = length - 1;

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
                right = mid;
            }
        }

        return -1;
    }
};
#endif // !_BIRNARY_SEARCH_HPP_