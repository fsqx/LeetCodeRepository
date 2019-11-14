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
    bool isValid(string str)
    {
        m_mapForString.insert('[', ']');
        m_mapForString.insert('(', ')');
        m_mapForString.insert('{', '}');
        stack<char> m_charStack;
        const char *c = str.c_str();

        while((*c) != 0)
        {
            if(m_mapForString.find((*c)) != m_mapForString.end())
            {
                m_charStack.push((*c));
            }
            else
            {
                char tmp_c = m_charStack.top();
                m_charStack.pop();

                if(m_mapForString.find(tmp_c)->second == (*c))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }

        return true;
    }
private:
    map<char, char> m_mapForString;
}£»