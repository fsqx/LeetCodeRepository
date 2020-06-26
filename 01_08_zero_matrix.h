#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        vector<bool> rowFlag(matrix.size());
        vector<int> colFlag;

        for(int row = 0; row < matrix.size(); row++)
        {
            for(int col = 0; col < matrix.at(row).size(); col++)
            {
                if(matrix.at(row).at(col) == 0)
                {
                    rowFlag[row] = true;

                    if(find(colFlag.begin(), colFlag.end(), col) == colFlag.end())
                    {
                        colFlag.push_back(col);
                    }
                }
            }
        }

        for(int row = 0; row < matrix.size(); row++)
        {
            if(rowFlag.at(row))
            {
                vector<int> &rowMatrix = matrix[row];

                for(int &elem : rowMatrix)
                {
                    elem = 0;
                }
            }
            else
            {
                auto &rowMatrix = matrix[row];

                for(int &index : colFlag)
                {
                    rowMatrix[index] = 0;
                }
            }
        }
    }
};