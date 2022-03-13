#pragma once
#include <string>
using namespace std;

class Solution
{
    enum class RegType
    {
        Normal          = 0x00001,  // aa
        RegularStar,                // a*
        RegularPoint,               // a.
        PointWithStar,              // .*
        PointWithLetter,            // .a
        Illegal                     // *a *.
    };

    enum class MatchResult
    {
        Matching = 0x01,    // 匹配
        MisMatching,        // 不匹配
        Continue,           // 匹配并且继续匹配
        Jump,               // 跳过该字符
        End
    };

    struct t_matchStack
    {
        char letter;
        char flag;
        short times;
    };
    using MatchStack = struct t_matchStack;

private:
    MatchStack m_matchStack;
    int m_sIndex;
    int m_pIndex;
    string m_sString;
    string m_pString;
    MatchResult m_result;

public:
    Solution()
    {
        m_matchStack = { 'a', 0 };
        m_sIndex = 0;
        m_pIndex = 0;
        m_result = MatchResult::MisMatching;
    }

    bool isMatch(string s, string p)
    {
        m_sString = s;
        m_pString = p;
        m_result = MatchResult::MisMatching;

        while(!isEnd())
        {
            m_result = matchOnce();

            if(m_result == MatchResult::MisMatching)
            {
                break;
            }
        }

        if(m_result == MatchResult::MisMatching || m_result == MatchResult::End)
        {
            return false;
        }

        return true;
    }

    MatchResult matchOnce()
    {
        // 处理一遍
        RegType currentType = getMatchType();
        MatchResult resultType = MatchResult::MisMatching;

        switch(currentType)
        {
            case RegType::Normal:
            case RegType::RegularPoint:
                resultType = matchNormal();
                break;

            case RegType::RegularStar:
                resultType = matchStar();
                break;

            case RegType::PointWithStar:
                resultType = matchPointWithStar();
                break;

            case RegType::PointWithLetter:
                resultType = matchPointWithLetter();
                break;

            case RegType::Illegal:
                {
                    resultType = MatchResult::Jump;
                }
                break;

            default:
                m_pIndex++;
                resultType = MatchResult::Jump;
                break;
        }

        return resultType;
    }


    RegType getMatchType()
    {
        char firstLetter = 0;
        char secondLetter = 0;

        if(m_pIndex < m_pString.length() - 1)
        {
            firstLetter = m_pString.at(m_pIndex);
            secondLetter = m_pString.at(m_pIndex + 1);
        }
        else if(m_pIndex == m_pString.length() - 1)
        {
            firstLetter = m_pString.at(m_pIndex);

            if(firstLetter <= 'z' && firstLetter >= 'a')
            {
                return RegType::Normal;
            }
            else if(firstLetter == '.')
            {
                return RegType::RegularPoint;
            }
            else
            {
                return RegType::Illegal;
            }
        }

        if(firstLetter <= 'z' && firstLetter >= 'a')
        {
            // aa
            if(secondLetter <= 'z' && secondLetter >= 'a')
            {
                return RegType::Normal;
            }
            // a*
            else if(secondLetter == '*')
            {
                return RegType::RegularStar;
            }
            // a.
            else if(secondLetter == '.')
            {
                return RegType::RegularPoint;
            }
        }

        // .* .a
        if(firstLetter == '.')
        {
            if(secondLetter == '*')
            {
                return RegType::PointWithStar;
            }
            else
            {
                return RegType::PointWithLetter;
            }
        }

        // 其他情况应跳过该字符
        return RegType::Illegal;
    }

    MatchResult matchNormal()
    {
        char sPtr = 0;
        char pPtr = 0;

        if(m_sIndex < m_sString.length())
        {
            sPtr = m_sString.at(m_sIndex);
        }

        if(m_pIndex < m_pString.length())
        {
            pPtr = m_pString.at(m_pIndex);
        }

        if(sPtr == pPtr)
        {
            m_sIndex++;
            m_pIndex++;
            m_matchStack.letter = sPtr;
            m_matchStack.times = 1;
            m_matchStack.flag = sPtr;
            return MatchResult::Matching;
        }
        else
        {
            if(m_matchStack.flag == '*')
            {
                // 匹配a*a
                if(m_matchStack.letter == pPtr)
                {
                    m_matchStack.times--;
                    m_pIndex++;
                    return MatchResult::Matching;
                }
            }
        }

        return MatchResult::MisMatching;
    }

    MatchResult matchStar()
    {
        char sPtr = 0;
        char pPtr = 0;

        if(m_sIndex < m_sString.length())
        {
            sPtr = m_sString.at(m_sIndex);
        }

        if(m_pIndex < m_pString.length())
        {
            pPtr = m_pString.at(m_pIndex);
        }

        m_matchStack.letter = sPtr;
        m_matchStack.times = 0;

        while(sPtr == pPtr)
        {
            m_matchStack.times++;
            m_matchStack.flag = '*';
            m_sIndex++;

            if(m_sIndex < m_sString.length())
            {
                sPtr = m_sString.at(m_sIndex);
            }
            else
            {
                break;
            }
        }

        m_pIndex += 2;
        return MatchResult::Matching;
    }

    MatchResult matchPointWithStar()
    {
        char sPtr = 0;
        char pPtr = 0;

        if(m_sIndex < m_sString.length())
        {
            sPtr = m_sString.at(m_sIndex);
        }

        if(m_pIndex < m_pString.length())
        {
            pPtr = sPtr;
        }

        m_matchStack.letter = sPtr;
        m_matchStack.times = 0;

        while(sPtr == pPtr)
        {
            m_matchStack.times++;
            m_matchStack.flag = '*';
            m_sIndex++;

            if(m_sIndex < m_sString.length())
            {
                sPtr = m_sString.at(m_sIndex);
            }
        }

        m_pIndex++;
        return MatchResult::Matching;
    }

    MatchResult matchPointWithLetter()
    {
        char sPtr = 0;
        char pPtr = 0;

        if(m_sIndex < m_sString.length())
        {
            sPtr = m_sString.at(m_sIndex);
        }

        if(m_pIndex < m_pString.length())
        {
            pPtr = sPtr;
        }

        if(sPtr == pPtr)
        {
            m_sIndex++;
            m_pIndex++;
            m_matchStack.letter = sPtr;
            m_matchStack.times = 1;
            m_matchStack.flag = sPtr;
            return MatchResult::Matching;
        }

        return MatchResult::MisMatching;
    }

    bool isEnd()
    {
        // 是否结束的标记
        if(m_sIndex <= (m_sString.length() - 1) && m_pIndex <= (m_pString.length() - 1))
        {
            return false;
        }

        if(m_sIndex <= (m_sString.length() - 1) && m_pIndex > (m_pString.length() - 1))
        {
            m_result = MatchResult::End;
            return true;
        }

        if(m_sIndex > (m_sString.length() - 1) && m_pIndex <= (m_pString.length() - 1))
        {
            m_result = MatchResult::End;
            return true;
        }

        return true;
    }

};