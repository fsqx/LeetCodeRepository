#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) 
    {
        string rstNumString = "1";
        for(int i = 0; i < n; i++)
        {
            rstNumString = countAndSayStr(rstNumString);
        }
    }

    string countAndSayStr(string &numString)
    {
        // 控制生成新字符串
        char tmpStr[100];
        int strIndex = 0;
        // 计算字符个数
        int count = 1;
        char tmpChar = numString.at(1);

        for(int i = 1; i < numString.size(); i++)
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

int main()
{
    Solution solution;
    cout << solution.countAndSay(1) << endl;

    system("pause");
    return 0;
}