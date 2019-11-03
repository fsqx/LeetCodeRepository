/*
* ����˼·��
* 1. ���ַ���ת�������֣�Ȼ�����崦�����vector�У���һ�鴦����ͬ��������ڶ���С�ڣ��������ۺ͡�
* 2. һ�鴦���ַ�������Ŀת��Ϊ�������ֵС����ֵ�ͼ�ȥ��ֵ�������ֵ������ֵ�ͼ�����ֵ��
* 3. ע��Խ�������
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

        // �����ֵС����ֵ�ͼ�ȥ��ֵ�������ֵ������ֵ�ͼ�����ֵ��
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

        // ������ͬ��Ԫ��
        for(int i = 1; i < src_numbers.size(); i++)
        {
            // �ж��Ƿ�����ͬ��Ԫ��
            if(src_numbers.at(i) == src_numbers.at(i - 1))
            {
                temp += src_numbers.at(i);
            }
            else
            {
                none_same_numbers.push_back(temp);
                temp = src_numbers.at(i);
            }

            // �������һ��Ԫ��
            if(i == src_numbers.size() - 1)
            {
                none_same_numbers.push_back(temp);
            }
        }

        // ����С�ڵ�Ԫ��
        vector<int> less_than_number;

        for(int i = 0; i < none_same_numbers.size(); i++)
        {
            // ��ֹvectorԽ��
            if(i == none_same_numbers.size() - 1)
            {
                less_than_number.push_back(none_same_numbers.at(i));
            }
            // �ж�С����ֵ�����
            else if(none_same_numbers.at(i) < none_same_numbers.at(i + 1))
            {
                less_than_number.push_back(none_same_numbers.at(i + 1) - none_same_numbers.at(i));
                i++;
            }
            // ������ֵ�����
            else
            {
                less_than_number.push_back(none_same_numbers.at(i));
            }
        }

        // ������ڵ����
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