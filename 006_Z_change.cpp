#include <iostream>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int srcLength = s.size();
        m_col = 0;
        m_row = numRows;
        m_numRows = numRows;
        m_col += s.size() / (2 * numRows - 2) * (numRows - 1);
        int remaining = s.size() % (2 * numRows - 2);
        if (remaining <= numRows)
        {
            m_col += 1;
        }
        else
        {
            m_col += remaining % numRows + 1;
        }
        // 转换二维数组
        char *srcStringArray = new char[m_col * m_row];
        // 转换到二维数组中
        int left = 0;
        int right = 0;
        for (int i = 0; i < s.length(); i++)
        {
        }
    }

    bool getPoint(int &left, int &right)
    {
        if(right % (m_numRows - 1) == 0)
        {
            if(left != m_numRows)
            {
                
            }
        }
    }

private:
    int m_row;
    int m_col;
    int m_numRows;
};

int main()
{
    cout << "hello world!" << endl;
    system("pause");
    return 0;
}