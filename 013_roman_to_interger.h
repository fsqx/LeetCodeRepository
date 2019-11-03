/*
* 解题思路：
* 1. 将字符串转化成数字，然后整体处理存入vector中，第一遍处理相同的情况，第二遍小于，第三遍累和。
* 2. 一遍处理字符串，题目转换为：如果左值小于右值就减去左值，如果左值大于右值就加上右值。
* 3. 注意越界情况。
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int romanToInt(string s)
    {
        auto length = s.length();
        vector<int> src_numbers(length, 0);
        int result;

        // 如果左值小于右值就减去左值，如果左值大于右值就加上右值。
        for(int i = 0; i < length; i++)
        {
            if(i < length - 1 && getIntFromChar(*(s.c_str() + i)) < getIntFromChar(*(s.c_str() + i + 1)))
            {
                result += getIntFromChar(*(s.c_str() + i));
            }
            else
            {
                result -= getIntFromChar(*(s.c_str() + i));
            }
        }

        return result;
    }

    int romanToInt_old(string s)
    {
        auto length = s.length();
        vector<int> src_numbers(length, 0);

        for(int i = 0; i < length; i++)
        {
            src_numbers[i] = getIntFromChar(*(s.c_str() + i));
        }

        vector<int> none_same_numbers;
        int temp = src_numbers.at(0);

        if(src_numbers.size() == 1)
        {
            none_same_numbers.push_back(temp);
        }

        // 处理相同的元素
        for(int i = 1; i < src_numbers.size(); i++)
        {
            // 判定是否有相同的元素
            if(src_numbers.at(i) == src_numbers.at(i - 1))
            {
                temp += src_numbers.at(i);
            }
            else
            {
                none_same_numbers.push_back(temp);
                temp = src_numbers.at(i);
            }

            // 处理最后一个元素
            if(i == src_numbers.size() - 1)
            {
                none_same_numbers.push_back(temp);
            }
        }

        // 处理小于的元素
        vector<int> less_than_number;

        for(int i = 0; i < none_same_numbers.size(); i++)
        {
            // 防止vector越界
            if(i == none_same_numbers.size() - 1)
            {
                less_than_number.push_back(none_same_numbers.at(i));
            }
            // 判定小于右值的情况
            else if(none_same_numbers.at(i) < none_same_numbers.at(i + 1))
            {
                less_than_number.push_back(none_same_numbers.at(i + 1) - none_same_numbers.at(i));
                i++;
            }
            // 大于右值的情况
            else
            {
                less_than_number.push_back(none_same_numbers.at(i));
            }
        }

        // 处理大于的情况
        int result = 0;

        for(int i = 0; i < less_than_number.size(); i++)
        {
            result += less_than_number.at(i);
        }

        return result;
    }

    int getIntFromChar(char c)
    {
        if(c == 'I')
        {
            return 1;
        }
        else if(c == 'V')
        {
            return 5;
        }
        else if(c == 'X')
        {
            return 10;
        }
        else if(c == 'L')
        {
            return 50;
        }
        else if(c == 'C')
        {
            return 100;
        }
        else if(c == 'D')
        {
            return 500;
        }
        else if(c == 'M')
        {
            return 1000;
        }
        else
        {
            return 0;
        }
    }
};