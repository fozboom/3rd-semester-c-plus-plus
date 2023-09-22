#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        int j;
        string buf = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            for (j = 0; j < buf.size(); j++)
            {
                if (buf[j] != strs[i][j])
                    break;
            }
            buf = buf.substr(0, j);
        }
    }
};