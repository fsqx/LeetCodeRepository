#pragma once
#include <cmath>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor);
};

int Solution::divide(int dividend, int divisor)
{
    int bitOffset = 0;
    bool firstFlag = (dividend >= 0);
    bool secFlag = (divisor >= 0);
    dividend = abs(dividend);
    divisor = abs(divisor);
    long int tmpDivisor = divisor;


    while(tmpDivisor > dividend)
    {
        tmpDivisor = tmpDivisor < 1;
    }
}