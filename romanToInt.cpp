#include <iostream>
using namespace std;

/*
M - 1000
D - 500
C - 100
L - 50
X - 10
V - 5
I - 1

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.

III - 3
LVIII - 58
MCMXCIV - 1994
*/

int romanToInt(string roman)
{
    int number = 0;

    for (int i = 0; i < roman.size(); i++)
    {

        switch (roman[i])
        {
        case 'M':
            number += 1000;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'C')
                {
                    number -= 200;
                }
            }
            break;
        case 'D':
            number += 500;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'C')
                {
                    number -= 200;
                }
            }
            break;
        case 'C':
            number += 100;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'X')
                {
                    number -= 20;
                }
            }
            break;
        case 'L':
            number += 50;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'X')
                {
                    number -= 20;
                }
            }
            break;
        case 'X':
            number += 10;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'I')
                {
                    number -= 2;
                }
            }
            break;
        case 'V':
            number += 5;
            if (i > 0)
            {
                int prevChar = roman[i - 1];
                if (prevChar == 'I')
                {
                    number -= 2;
                }
            }
            break;
        case 'I':
            number += 1;
            break;
        }
    }

    return number;
}

int main()
{

    string roman;
    cin >> roman;
    int number = romanToInt(roman);
    cout << number << endl;
}