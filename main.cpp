#include <iostream>
class Solution {
public:
    int romanSwitch(char s)
    {
        switch(s)
        {
            case 'I': {
                return 1;
            }
            case 'V': {
                return 5;
            }
            case 'X': {
                return 10;
            }
            case 'L': {
                return 50;
            }
            case 'C': {
                return 100;
            }
            case 'D': {
                return 500;
            }
            case 'M': {
                return 1000;
            }
            default:
                return 0;
        }
    }

    int romanToInt(std::string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (romanSwitch(s[i]) < romanSwitch(s[i+1]))
            {
               sum -= s[i];
            }
            else
            {
                sum += s[i];
            }
        }
        return sum;
    }


};
