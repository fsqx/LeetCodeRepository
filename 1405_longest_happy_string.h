#pragma once

#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		string rst;
		vector<pair<int, char> > arr = { {a, 'a'}, {b, 'b'}, {c, 'c'} };

		while (true)
		{
			sort(begin(arr), end(arr), [](const pair<int, char> &p1, const pair<int, char> &p2) {
				return p1.first > p2.first;
			});
			auto &[freq, ch] = arr.at(0);
			if (freq == 0 || (rst.length() >= 2 && *(rst.rbegin()) == ch && *(rst.rbegin() + 1) == ch))
			{
				break;
			}

			bool flag = false;

			for (auto &[freq, ch] : arr)
			{
				if (freq == 0)
				{
					break;
				}

				if (flag)
				{
					rst.push_back(ch);
					freq--;
					flag = false;
					break;
				}
				int num = 0;

				if ((rst.length() > 2 && ch != *rst.rbegin()) || rst.length() < 2)
				{
					num = min(freq, 2);
				}
				else if(rst.length() > 2 && ch == *rst.rbegin())
				{
					num = min(freq, 1);
				}

				for (auto i = 0; i < num; i++)
				{
					rst.push_back(ch);
					freq--;
					flag = true;
				}
			}
		}
		return rst;
	}
};