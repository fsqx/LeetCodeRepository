#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if(n == 1)
        {
            return string("1");
        }

        string rstNumString = "1";

        for(int i = 0; i < n; i++)
        {
            rstNumString = countAndSayStr(rstNumString);
        }

        return rstNumString;
    }

    string countAndSayStr(string &numString)
    {
        // 控制生成新字符串
        char tmpStr[100];
        int strIndex = 0;
        // 计算字符个数
        int count = 0;
        char tmpChar = ' ';

        for(int i = 0; i < numString.size(); i++)
        {
            if(numString.at(i) != tmpChar)
            {
                tmpStr[strIndex] = count;
                strIndex++;
                tmpStr[strIndex] = tmpChar;
                strIndex++;
                count = 1;
                tmpChar = numString.at(i);
            }
            else
            {
                count++;
            }
        }

        tmpStr[strIndex] = '\0';
        return string(tmpStr);
    }
};

/*
int main()
{
    Solution solution;
    cout << solution.countAndSay(2) << endl;
    system("pause");
    return 0;
}
*/