#pragma once
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    Solution()
    {
        m_mapForString.insert(pair<char, char>(']', '['));
        m_mapForString.insert(pair<char, char>(')', '('));
        m_mapForString.insert(pair<char, char>('}', '{'));
    }
    bool isValid(string str)
    {
        stack<char> m_charStack;
        const char *c = str.c_str();

        while((*c) != 0)
        {
            auto iter = m_mapForString.find(*c);

            if(iter == m_mapForString.end())
            {
                m_charStack.push(*c);
            }
            else
            {
                if(!m_charStack.empty() && iter->second == m_charStack.top())
                {
                    m_charStack.pop();
                }
                else
                {
                    return false;
                }
            }

            c++;
        }

        if(m_charStack.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }


private:
    map<char, char> m_mapForString;
};