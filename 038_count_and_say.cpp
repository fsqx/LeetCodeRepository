#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return string("1");
        }
        string rstNumString = "1";
        for (int i = 0; i < n; i++)
        {
            rstNumString = countAndSayStr(rstNumString);
        }
        return rstNumString;
    }

    string countAndSayStr(string &numString)
    {
        // 控制生成新字符串
        string tmpStr;
        int strIndex = 0;
        // 计算字符个数
        int count = 0;
        char tmpChar = ' ';

        for (int i = 0; i < numString.size(); i++)
        {
            if (numString.at(i) != tmpChar)
            {
                if (tmpChar <= '9' && tmpChar >= '0')
                {
                    tmpStr += (count + '0');
                    strIndex++;
                    tmpStr += tmpChar;
                    strIndex++;
                }

                count = 1;
                tmpChar = numString.at(i);
            }
            else
            {
                count++;
            }

            if (i == numString.size() - 1)
            {
                tmpStr += count + '0';
                strIndex++;
                tmpStr += tmpChar;
                strIndex++;
            }
        }
        tmpStr[strIndex] = '\0';
        return string(tmpStr);
    }
};

int main()
{          
    Solution solution;
    cout << solution.countAndSay(20) << endl;
    system("pause");
    return 0;
}